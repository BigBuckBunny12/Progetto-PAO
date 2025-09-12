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
    const int ICON_SIZE = 32;
    QPixmap pixmap(path);
    QPixmap scaledPixmap = pixmap.scaled(ICON_SIZE, ICON_SIZE, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    icon->setPixmap(scaledPixmap);
    icon->setFixedSize(ICON_SIZE, ICON_SIZE);
    icon->setAlignment(Qt::AlignCenter);
}

void ViewMediaCreationVisitor::visit(Book& book) {
    setIcon(":/resources/img/book_icon.png");
    addStringField("Titolo", book.getTitle());
    addStringField("Anno di pubblicazione", QString::number(book.getPublicationYear()));
    addStringField("Autore", book.getAuthor());
    addStringField("Numero pagine", QString::number(book.getTotalPages()));
    addStringField("Editore", book.getPublisher());
    addStringField("Genere", Book::genreLabels().at(book.getGenre()));
    addImageField("Copertina", book.getCoverImageUrl());
}

void ViewMediaCreationVisitor::visit(Movie& movie) {
    setIcon(":/resources/img/movie_icon.png");
    addStringField("Titolo", movie.getTitle());
    addStringField("Anno di pubblicazione", QString::number(movie.getPublicationYear()));
    addStringField("Durata", formatMinutes(movie.getDuration()));
    addStringField("Produttore", movie.getProducer());
    addImageField("Copertina", movie.getCoverImageUrl());
}

void ViewMediaCreationVisitor::visit(Article& article) {
    setIcon(":/resources/img/article_icon.png");
    addStringField("Titolo", article.getTitle());
    addStringField("Anno di pubblicazione", QString::number(article.getPublicationYear()));
    addStringField("Fonte", article.getSource());
    addStringField("DOI", article.getDoi());
    addStringField("Numero fascicolo", QString::number(article.getIssueNumber()));
    addStringField("Articolo scientifico", article.getIsScientificPaper() ? "Sì" : "No");
    addImageField("Copertina", article.getCoverImageUrl());
}
