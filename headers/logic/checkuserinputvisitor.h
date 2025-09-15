#ifndef CHECKUSERINPUTVISITOR_H
#define CHECKUSERINPUTVISITOR_H

#include "getuserinputvisitor.h"
#include "mediaconstvisitor.h"
#include <qformlayout.h>

class CheckUserInputVisitor : public MediaConstVisitor
{
public:
    CheckUserInputVisitor(MediaInput input): userInput(input), isValidInput(true) {}

    void visit(const Book& book) override;
    void visit(const Movie& movie) override;
    void visit(const Article& article) override;
    bool getResult() const;
    std::vector<QString> getErrorFeedback() const;

private:
    MediaInput userInput;
    bool isValidInput;
    void checkInputNotEmpty(const QVariant& input, const QString errorMessage);
    void checkPositiveInteger(const QVariant& input, const QString errorMessage, const int threshold = 2147483647);
    void checkValidYear(const QVariant& input);
    void checkValidDoi(const QVariant& input);
    void clearFeedback();
    std::vector<QString> feedback;
};

#endif // CHECKUSERINPUTVISITOR_H
