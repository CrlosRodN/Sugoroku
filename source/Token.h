#ifndef TOKEN_H
#define TOKEN_H

#include <QSvgWidget>

class Token : public QSvgWidget
{
    private:


    public:
        explicit Token( const char* svg, QSvgWidget *parent = 0);
        ~Token();

        bool active;

    protected:
        virtual void mouseDoubleClickEvent( QMouseEvent* ) override;
};

#endif // TOKEN_H
