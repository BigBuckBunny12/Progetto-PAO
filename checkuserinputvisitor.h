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

private:
    MediaInput userInput;
    bool isValidInput;
    void checkInputNotEmpty(const QVariant& input);
    void checkPositiveInteger(const QVariant& input, const int threshold = 2147483647);
    void checkValidYear(const QVariant& input);
};

#endif // CHECKUSERINPUTVISITOR_H
