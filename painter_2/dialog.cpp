#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QString>

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
    QString st = QCoreApplication::applicationDirPath();
    getpng = pix.load("../../logo.png");
    if (getpng)
    painter.drawPixmap(0, 0, 129, 66, pix);

    painter.setPen(Qt::blue);
    painter.drawLine(QPointF(0, 0), QPointF(100, 100));

    painter.translate(100, 100); //将（100，100）设为坐标原点
    painter.drawPixmap(0, 0, 129, 66, pix);
    qreal width = pix.width(); //获得以前图片的宽和高
    qreal height = pix.height();
    //将图片的宽和高都扩大两倍，并且在给定的矩形内保持宽高的比值不变
    pix = pix.scaled(width*2, height*2, Qt::KeepAspectRatio);
    painter.drawPixmap(70, 70,pix);

    painter.setPen(Qt::red);
    painter.drawLine(QPointF(0, 0), QPointF(70, 70));

    painter.setPen(Qt::cyan);
    painter.drawLine(QPointF(0, 0), QPointF(64, 33));

    painter.translate(64, 33); //让图片的中心作为旋转的中心

    painter.rotate(90); //顺时针旋转90度

    painter.setPen(Qt::yellow);
    painter.drawLine(QPointF(0, 0), QPointF(-33, 64));
    painter.translate(-64,-33); //使原点复原


    painter.setPen(Qt::black);
    painter.drawLine(QPointF(0, 0), QPointF(100, 100));

    painter.drawPixmap(100, 100, 129, 66, pix);

    painter.shear(0.5, 0); //横向扭曲
    painter.drawPixmap(100, 0, 129, 66, pix);

}
