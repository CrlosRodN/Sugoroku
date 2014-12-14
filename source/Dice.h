#ifndef DICE_H
#define DICE_H

#include <QImageReader>
#include <QImage>
#include <QLabel>
#include <QTimer>
#include <ctime>
#include <algorithm>
#include <cstdlib>

class Dice : public QLabel
{
    Q_OBJECT

    private:
        QVector<QString> dice_faces;
        QVector<QString>::const_iterator it;
        QTimer *timer;

    public:
        explicit Dice( QWidget * parent = 0 );
        virtual ~Dice();
        QImageReader* reader;

        int value;
        void charge_faces();
        void roll();
        void shuffle();

    public slots:
        void test( );
};

#endif // DICE_H
