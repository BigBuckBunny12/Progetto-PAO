#ifndef MEDIAWIDGETVISITOR_H
#define MEDIAWIDGETVISITOR_H

#include "media.h"
#include "mediaconstvisitor.h"

class MediaWidgetVisitor : public MediaConstVisitor
{
    public:
        enum class Behavior {
            CREATE,
            UPDATE
        };

        MediaWidgetVisitor(Media& media) : mediaWidget(media) {};
        void visit(const Book& book) override;
        void visit(const Movie& movie) override;
        void visit(const Article& article) override;

    private:
        Media& mediaWidget;
        Behavior behavior = Behavior::CREATE;
};

#endif // MEDIAWIDGETVISITOR_H
