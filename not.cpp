#include "not.h"



void Not::ritaNot(QPainter *qp, int x, double typ)
{
    //..
    //använd QPainter och pixmap tillsammans på nåt vänster
    if(typ == 0.5) {
        qp->drawPixmap(QRect(x, (375-(8*(this->getHeight()))), 71, 71), pixmap);
    }

    if(typ == 1.5){
        //QPixmap halfpix("G:/OOP/Lab7/half.png");
        pixmap = QPixmap("G:/OOP/Lab7/half.png");
        position = QRect(x, (375-(8*(this->getHeight()))), 71, 71);
        qp->drawPixmap(position, pixmap);
    }
}

void Not::setHeight(int hojd)
{
    _hojd = hojd;
}
void Not::setLength(int length)
{
    _langd = length;
}
int Not::getHeight()
{
    return _hojd;
}
int Not::getLength()
{
    return _langd;
}
