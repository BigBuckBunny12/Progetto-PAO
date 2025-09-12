#ifndef CHECKUSERINPUTVISITOR_H
#define CHECKUSERINPUTVISITOR_H

#include "GetUserInputVisitor.h"
#include "MediaVisitor.h"
#include <qformlayout.h>

class CheckUserInputVisitor : public MediaVisitor
{
public:
    CheckUserInputVisitor(MediaInput input): userInput(input), isValidInput(true) {}

    void visit(Book& book) override;
    void visit(Movie& movie) override;
    void visit(Article& article) override;
    bool getResult() const;
    std::vector<QString> getErrorFeedback() const;

private:
    MediaInput userInput;
    bool isValidInput;
    void checkInputNotEmpty(const QVariant& input, const QString errorMessage);
    void checkPositiveInteger(const QVariant& input, const QString errorMessage, const int threshold = 2147483647);
    void checkValidYear(const QVariant& input);
    void clearFeedback();
    std::vector<QString> feedback;
};

#endif // CHECKUSERINPUTVISITOR_H
