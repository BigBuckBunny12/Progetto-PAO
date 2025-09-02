#ifndef MEDIAWIDGETVISITOR_H
#define MEDIAWIDGETVISITOR_H

#include "media.h"
#include "mediavisitor.h"

class MediaWidgetVisitor : public MediaVisitor
{
    public:
        enum class Behavior {
            CREATE,
            UPDATE
        };

        MediaWidgetVisitor(Media& media) : mediaWidget(media) {};
        void visit(Book& book) override;
        void visit(Movie& movie) override;
        void visit(Article& article) override;

    private:
        Media& mediaWidget;
        Behavior behavior = Behavior::CREATE;
};

#endif // MEDIAWIDGETVISITOR_H
