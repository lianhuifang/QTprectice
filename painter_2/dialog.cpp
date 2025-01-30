#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    bool getpng = true;
    getpng = pix.load("D:/work/painter_2/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/image/logo.png");
    if (getpng)
    painter.drawPixmap(0, 0, 129, 66, pix);

}
