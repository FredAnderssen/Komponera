#ifndef NOT_H
#define NOT_H

#include <QPixmap>
#include <QPainter>

class Not
{
public:
    Not() : _hojd(0), _langd(0){}
    Not(int height, int length): _hojd(height), _langd(length) {}

    void ritaNot(QPainter * qp, int x, double typ);

    void setHeight(int hojd);
    void setLength(int length);
    int getHeight();
    int getLength();



private:
    QPixmap pixmap;
    QRect position;
    int _hojd;
    int _langd;

};

#endif // NOT_H
