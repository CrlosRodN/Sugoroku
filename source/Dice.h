#ifndef DICE_H
#define DICE_H

#include <QImageReader>
#include <QImage>
#include <QLabel>

class Dice : public QLabel
{

    public:
        explicit Dice( QWidget * parent = 0 );
        virtual ~Dice();

        int value;
        void roll();
};

#endif // DICE_H
