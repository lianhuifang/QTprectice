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
    getpng = pix.load("../../screem.png");
    if (getpng)
    painter.drawPixmap(0, 0, 300, 120, pix);

}
