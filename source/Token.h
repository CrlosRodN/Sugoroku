#ifndef TOKEN_H
#define TOKEN_H

#include <QSvgWidget>

class Token : public QSvgWidget
{
    Q_OBJECT

    private:


    public:
        explicit Token( const char* svg, QSvgWidget *parent = 0);
        ~Token();

    signals:
        void clicked( Token* );

    protected:
        virtual void mouseDoubleClickEvent( QMouseEvent* ) override;
};

#endif // TOKEN_H
