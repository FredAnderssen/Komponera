#ifndef KOMPOSITOR_H
#define KOMPOSITOR_H

#include <QMainWindow>
#include "notblad.h"
#include <QTimer>
#include <QPainter>
#include "Synthesizer.h"

namespace Ui {
class Kompositor;
}

class Kompositor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kompositor(QWidget *parent = 0);
    ~Kompositor();
    virtual void mousePressEvent(QMouseEvent* e);
    int pixelToHojd(int ypixel);
    void paintEvent(QPaintEvent *e);

    void ritaOm();

private slots:
    void on_n_quater_clicked();


    void on_n_half_clicked();

    void on_n_eight_clicked();

    void on_n_quaterest_clicked();

    void on_n_eightrest_clicked();

    void on_pushButton_clicked();

private:
    Ui::Kompositor *ui;
    Notblad notblad;
    int nottypval;

    int _x;
    int _y;
    QTimer * timer;

    Synthesizer synth;

};

#endif // KOMPOSITOR_H
