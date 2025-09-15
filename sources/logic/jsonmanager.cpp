#include "jsonmanager.h"
#include "qdir.h"
#include "qfileinfo.h"
#include "savemediavisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

JsonManager::JsonManager(QObject *parent)
    : QObject(parent) {}

JsonManager& JsonManager::instance() {
    static JsonManager instance;
    return instance;
}

void JsonManager::saveMediaData(const std::vector<IMedia*>& data, const QString& path) {
    QString filePath = path;
    if (!filePath.endsWith(".json", Qt::CaseInsensitive)) {
        filePath += ".json";
    }

    SaveMediaVisitor visitor;
    for (IMedia* media : data) {
        if (media) {
            media->accept(visitor);
        }
    }

    QJsonObject root = visitor.getResult();
    QJsonDocument doc(root);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qWarning() << "Impossibile aprire file per scrittura:" << filePath;
        return;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}

std::vector<IMedia*> JsonManager::loadMediaData(const QString& path) {
    std::vector<IMedia*> result;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Impossibile aprire il file per la lettura:" << path;
        return result;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Errore parsing JSON:" << parseError.errorString();
        return result;
    }

    if (!doc.isObject()) {
        qWarning() << "Formato JSON non valido (root non è un oggetto)";
        return result;
    }

    QJsonObject root = doc.object();
    QJsonArray mediaArray = root["mediaList"].toArray();

    QString baseDir = QFileInfo(path).absolutePath();

    int uid = 1;
    for (const QJsonValue& value : mediaArray) {
        if (!value.isObject()) continue;
        QJsonObject obj = value.toObject();

        QString type = obj["type"].toString();
        IMedia* media = nullptr;

        // Se il path è relativo, si ricostruisce il path assoluto
        QString coverPath = obj["coverImagePath"].toString();
        if (QDir::isRelativePath(coverPath)) {
            coverPath = QDir(baseDir).filePath(coverPath);
        }

        if (type == "Book") {
            media = new Book(
                coverPath,
                obj["title"].toString(),
                obj["year"].toInt(),
                obj["author"].toString(),
                obj["pages"].toInt(),
                obj["publisher"].toString(),
                Book::keyToGenre(obj["genre"].toString())
                );
        } else if (type == "Movie") {
            media = new Movie(
                coverPath,
                obj["title"].toString(),
                obj["year"].toInt(),
                obj["duration"].toInt(),
                obj["producer"].toString()
                );
        } else if (type == "Article") {
            media = new Article(
                coverPath,
                obj["title"].toString(),
                obj["year"].toInt(),
                obj["source"].toString(),
                obj["doi"].toString(),
                obj["issueNumber"].toInt(),
                obj["isScientificPaper"].toBool()
                );
        } else {
            qWarning() << "Il tipo" << type << "non è un tipo valido e sarà saltato";
            continue;
        }
        media->setUid(uid);
        uid++;

        if (media) {
            result.push_back(media);
        }
    }

    MediaManager::instance().clearMediaList();

    for (IMedia* media : result) {
        MediaManager::instance().addMedia(media);
    }

    return result;
}
