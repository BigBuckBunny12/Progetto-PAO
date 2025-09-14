#include "viewmediacreationvisitor.h"

void ViewMediaCreationVisitor::addStringField(const QString& label, const QString& value) {
    QLabel* field = new QLabel(QString("<b>%1:</b> %2").arg(label, value), parent);
    infoLayout->addWidget(field);
}

void ViewMediaCreationVisitor::addImageField(const QString &label, const QString &imagePath) {
    QLabel* labelWidget = new QLabel(QString("<b>%1:</b>").arg(label), parent);
    infoLayout->addWidget(labelWidget);

    QLabel* imageLabel = new QLabel(parent);
    QPixmap pixmap(imagePath);
    const float IMAGE_SCALE = 0.66;
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(parent->width() * IMAGE_SCALE, pixmap.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        imageLabel->setText("Nessuna immagine disponibile");
        imageLabel->setAlignment(Qt::AlignCenter);
    }
    infoLayout->addWidget(imageLabel);
}

void ViewMediaCreationVisitor::addDoi(const QString& label, const QString& value) {
    const QString url = QString("https://doi.org/%1").arg(value);

    QLabel* field = new QLabel(
        QString("<b>%1:</b> <a href=\"%2\">%3</a>")
            .arg(label, url, value),
        parent
    );

    field->setTextFormat(Qt::RichText);
    field->setTextInteractionFlags(Qt::TextBrowserInteraction);
    field->setOpenExternalLinks(true);
    infoLayout->addWidget(field);
}

QString ViewMediaCreationVisitor::formatMinutes(const int totalMinutes) const {
    const int MINUTES_IN_DAY = 24 * 60;
    const int MINUTES_IN_HOUR = 60;

    int days = totalMinutes / MINUTES_IN_DAY;
    int hours = (totalMinutes % MINUTES_IN_DAY) / MINUTES_IN_HOUR;
    int minutes = totalMinutes % MINUTES_IN_HOUR;
    QStringList parts;

    if (days > 0)
        parts << QString("%1g").arg(days);

    if (hours > 0 || days > 0)
        parts << QString("%1h").arg(hours);

    parts << QString("%1m").arg(minutes);
    return parts.join(" ");
}

void ViewMediaCreationVisitor::setIcon(const QString& path) {
    QPixmap pixmap(path);
    QPixmap scaledPixmap = pixmap.scaled(ICON_SIZE, ICON_SIZE, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    icon->setPixmap(scaledPixmap);
    icon->setFixedSize(ICON_SIZE, ICON_SIZE);
    icon->setAlignment(Qt::AlignCenter);
}

void ViewMediaCreationVisitor::visit(const Book& book) {
    setIcon(":/resources/img/book_icon.png");
    addStringField("Titolo", book.getTitle());
    addStringField("Anno di pubblicazione", QString::number(book.getPublicationYear()));
    addStringField("Autore", book.getAuthor());
    addStringField("Numero pagine", QString::number(book.getTotalPages()));
    addStringField("Editore", book.getPublisher());
    addStringField("Genere", Book::genreLabels().at(book.getGenre()));
    addImageField("Copertina", book.getCoverImagePath());
}

void ViewMediaCreationVisitor::visit(const Movie& movie) {
    setIcon(":/resources/img/movie_icon.png");
    addStringField("Titolo", movie.getTitle());
    addStringField("Anno di pubblicazione", QString::number(movie.getPublicationYear()));
    addStringField("Durata", formatMinutes(movie.getDuration()));
    addStringField("Regista", movie.getProducer());
    addImageField("Copertina", movie.getCoverImagePath());
}

void ViewMediaCreationVisitor::visit(const Article& article) {
    setIcon(":/resources/img/article_icon.png");
    addStringField("Titolo", article.getTitle());
    addStringField("Anno di pubblicazione", QString::number(article.getPublicationYear()));
    addStringField("Fonte", article.getSource());
    addDoi("DOI", article.getDoi());
    addStringField("Numero fascicolo", QString::number(article.getIssueNumber()));
    addStringField("Articolo scientifico", article.getIsScientificPaper() ? "Sì" : "No");
    addImageField("Copertina", article.getCoverImagePath());
}
