#include "kompositor.h"
#include "ui_kompositor.h"

#include <QMouseEvent>

Kompositor::Kompositor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kompositor)
{
    QPixmap("G:/OOP/Lab7/eight.png");
    QPixmap("G:/OOP/Lab7/eightc.png");
    QPixmap("G:/OOP/Lab7/eightrest.png");
    QPixmap("G:/OOP/Lab7/half.png");
    QPixmap("G:/OOP/Lab7/halfc.png");
    QPixmap("G:/OOP/Lab7/notblad.png");
    QPixmap("G:/OOP/Lab7/quater.png");
    QPixmap("G:/OOP/Lab7/quaterc.png");
    QPixmap("G:/OOP/Lab7/quaterrest.png");

    ui->setupUi(this);
}
Kompositor::~Kompositor()
{
    delete ui;
}
void Kompositor::on_n_half_clicked()
{
    nottypval = 1000;
}
void Kompositor::on_n_quater_clicked()
{
    //spara värde i nottypval
    //siffran är vilken Not du väljer
    nottypval = 500;
}
void Kompositor::on_n_eight_clicked()
{
    nottypval = 250;
}
void Kompositor::on_n_quaterest_clicked()
{
    nottypval = 500;
}

void Kompositor::on_n_eightrest_clicked()
{
    nottypval = 250;
}


void Kompositor::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        int temphojd = pixelToHojd(e->y());
        notblad.adderaNot(nottypval, temphojd);
        _x = 150;
        _y = e->y();

        ritaOm();
    }
    update();
}

void Kompositor::ritaOm()
{
    repaint();
}

int Kompositor::pixelToHojd(int ypixel)
{
    float elevel = 413;
    float step = 8;
    int height = -1;
    for (int i = 0; i < 12; i++) {
        if (ypixel <= (elevel + (2 - i)*step + step / 2) &&
                ypixel > (elevel + (2 - i)*step - step / 2))
            height = i;
    }
    return height;
}


Kompositor::Kompositor(QWidget *parent) : QMainWindow(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
}

void Kompositor::update()
{
    //updt noterna?
    repaint();
}

void Kompositor::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    for(int i =0; i<notblad.getNotes().size(); i++) {
        Not* temp = notblad.getNotes()[i];
        temp->ritaNot(&painter, _x); //detta ska vara efter alla ifsatser?
        _x += 40; //TODO Behövs _x argumentet? vill inte ha så

        //TODO _langd eller nottypval?
        if(nottypval == 1000) {
            if(temp->getHeight() == 0){
                QPixmap halfpixc("G:/OOP/Lab7/halfc.png");
                temp->pixmap(halfpixc);
            }
            else {
                QPixmap halfpix("G:/OOP/Lab7/half.png");
                temp->pixmap(halfpix);
            }
        }

        if(nottypval == 500) {
            if(temp->getHeight() == 0){
                QPixmap halfpixc("G:/OOP/Lab7/quaterc.png");
                temp->pixmap(halfpixc);
            }
            else {
                QPixmap halfpix("G:/OOP/Lab7/quater.png");
                temp->pixmap(halfpix);
            }
        }

        if(nottypval == 250) {
            if(temp->getHeight() == 0){
                QPixmap halfpixc("G:/OOP/Lab7/eightc.png");
                temp->pixmap(halfpixc);
            }
            else {
                QPixmap halfpix("G:/OOP/Lab7/eight.png");
                temp->pixmap(halfpix);
            }
        }




    }
}



