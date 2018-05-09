#include "kompositor.h"
#include "ui_kompositor.h"

Kompositor::Kompositor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kompositor)
{
    ui->setupUi(this);
}

Kompositor::~Kompositor()
{
    delete ui;
}
