#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include "imedia.h"
#include "mediamanager.h"
#include <QObject>

class JsonManager : public QObject
{
    Q_OBJECT

public:
    static JsonManager& instance();
    void saveMediaData(const std::vector<IMedia*>& data, const QString& path);
    std::vector<IMedia*> loadMediaData(const QString& path);

private:
    explicit JsonManager(QObject *parent = nullptr);
    JsonManager(const JsonManager&) = delete;
    JsonManager& operator=(const JsonManager&) = delete;
};

#endif // JSONMANAGER_H
