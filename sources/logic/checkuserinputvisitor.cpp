#include "checkuserinputvisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QDebug>
#include <QRegularExpression>
#include <qdatetime.h>
#include <qformlayout.h>

void CheckUserInputVisitor::checkInputNotEmpty(const QVariant& value, const QString errorMessage) {
    if (!value.isValid() || value.toString().trimmed().isEmpty()) {
        isValidInput = false;
        feedback.push_back(errorMessage);
    }
}

void CheckUserInputVisitor::checkPositiveInteger(const QVariant& value, const QString errorMessage, const int threshold) {
    if (!value.canConvert<int>() || value.toInt() <= 0 || value.toInt() > threshold) {
        isValidInput = false;
        feedback.push_back(errorMessage);
    }
}

void CheckUserInputVisitor::checkValidYear(const QVariant& value) {
    if (!value.canConvert<int>()) {
        isValidInput = false;
        feedback.push_back("L'anno non è un numero valido");
        return;
    }

    const int year = value.toInt();
    const int currentYear = QDate::currentDate().year();
    const int MIN_YEAR = 1000;
    if (year < 1000 || year > currentYear) {
        isValidInput = false;
        feedback.push_back(QString("Anno non valido: deve essere compreso tra %1 e %2").arg(MIN_YEAR).arg(currentYear));
    }
}

void CheckUserInputVisitor::checkValidDoi(const QVariant& value) {
    if (!value.isValid() || value.toString().trimmed().isEmpty()) {
        isValidInput = false;
        feedback.push_back("Il DOI non può essere vuoto");
        return;
    }

    QRegularExpression regex("\\b(10[.][0-9]{4,}(?:[.][0-9]+)*/(?:(?![\"&'<>])\\S)+)\\b");
    if(!regex.match(value.toString()).hasMatch()) {
        isValidInput = false;
        feedback.push_back("Il formato del DOI inserito non è valido");
    }
}

void CheckUserInputVisitor::visit(const Book& book) {
    feedback.clear();
    isValidInput = true;
    checkInputNotEmpty(userInput.value("title"), "Il titolo non può essere vuoto");
    checkValidYear(userInput.value("year"));
    checkInputNotEmpty(userInput.value("author"), "L'autore non può essere vuoto");
    checkPositiveInteger(userInput.value("pages"), "Numero di pagine non valido");
    checkInputNotEmpty(userInput.value("publisher"), "L'editore non può essere vuoto");
}

void CheckUserInputVisitor::visit(const Movie& movie) {
    feedback.clear();
    isValidInput = true;
    checkInputNotEmpty(userInput.value("title"), "Il titolo non può essere vuoto");
    checkValidYear(userInput.value("year"));
    checkPositiveInteger(userInput.value("duration"), "Durata non valida", 60 * 24);
    checkInputNotEmpty(userInput.value("producer"), "Il regista non può essere vuoto");
}

void CheckUserInputVisitor::visit(const Article& article) {
    feedback.clear();
    isValidInput = true;
    checkInputNotEmpty(userInput.value("title"), "Il titolo non può essere vuoto");
    checkValidYear(userInput.value("year"));
    checkInputNotEmpty(userInput.value("source"), "La fonte non può essere vuota");
    checkValidDoi(userInput.value("doi"));
    checkPositiveInteger(userInput.value("issueNumber"), "Numero di fascicolo non valido");
}

bool CheckUserInputVisitor::getResult() const {
    return isValidInput;
}

std::vector<QString> CheckUserInputVisitor::getErrorFeedback() const {
    return feedback;
}
