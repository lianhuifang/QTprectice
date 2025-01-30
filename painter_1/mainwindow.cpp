#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPainterPath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainterPath path;
    path.addRect(50, 50, 40, 40);
    path.moveTo(100, 100);
    path.lineTo(200, 200);
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::red);
    painter.drawPath(path);

    QPainterPath path2;
    path2.addPath(path);
    path2.translate(100,0);
    painter.drawPath(path2);
}
