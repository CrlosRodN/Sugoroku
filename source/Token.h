#ifndef TOKEN_H
#define TOKEN_H

#include <QSvgWidget>

class Token : public QSvgWidget
{
    private:


    public:
        explicit Token( const char* svg, QSvgWidget *parent = 0);
        ~Token();

    protected:
        virtual void mouseDoubleClickEvent( QMouseEvent* event ) override;
};

#endif // TOKEN_H
