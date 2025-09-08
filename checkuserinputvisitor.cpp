#include "CheckUserInputVisitor.h"
#include "book.h"
#include "movie.h"
#include "article.h"
#include <QDebug>
#include <qdatetime.h>
#include <qformlayout.h>

void CheckUserInputVisitor::checkInputNotEmpty(const QVariant& value) {
    if (!value.isValid() || value.toString().trimmed().isEmpty()) {
        isValidInput = false;
    }
}

void CheckUserInputVisitor::checkPositiveInteger(const QVariant& value, const int threshold) {
    if (!value.canConvert<int>() && value.toInt() <= 0 && value.toInt() <= threshold) {
        isValidInput = false;
        return;
    }
}

void CheckUserInputVisitor::checkValidYear(const QVariant& value) {
    if (!value.canConvert<int>()) {
        isValidInput = false;
        return;
    }

    int year = value.toInt();
    int currentYear = QDate::currentDate().year();

    if (year < 1000 || year > currentYear) {
        isValidInput = false;
    }
}

void CheckUserInputVisitor::visit(Book& book) {
    checkInputNotEmpty(userInput.value("title"));
    checkValidYear(userInput.value("year"));
    checkInputNotEmpty(userInput.value("author"));
    checkPositiveInteger(userInput.value("pages"));
    checkInputNotEmpty(userInput.value("publisher"));
}

void CheckUserInputVisitor::visit(Movie& movie) {
    checkInputNotEmpty(userInput.value("title"));
    checkValidYear(userInput.value("year"));
    checkPositiveInteger(userInput.value("duration"), 65535);
    checkInputNotEmpty(userInput.value("producer"));
}

void CheckUserInputVisitor::visit(Article& article) {
    checkInputNotEmpty(userInput.value("title"));
    checkValidYear(userInput.value("year"));
    checkInputNotEmpty(userInput.value("source"));
    checkInputNotEmpty(userInput.value("doi"));
    checkPositiveInteger(userInput.value("issueNumber"));
}

bool CheckUserInputVisitor::getResult() const {
    return isValidInput;
}
