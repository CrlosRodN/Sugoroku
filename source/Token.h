#ifndef TOKEN_H
#define TOKEN_H

#include <QSvgWidget>

class Token
{
    protected:
        const char* image;

    public:
        explicit Token( const char* svg );

//        Token(const char* svg);
       ~Token();

        QSvgWidget *tile;
};

#endif // TOKEN_H
