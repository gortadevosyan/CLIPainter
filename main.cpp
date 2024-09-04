#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include "lineitem.h"
#include "basegraphicsitem.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LineItem *line = new LineItem(1, 1, 300, 400, nullptr, "Line_1");
    QGraphicsLineItem *l = new QGraphicsLineItem(400, 400, 10, -100);
    QGraphicsRectItem *rect = new QGraphicsRectItem(100, 100, 50, 50);
    w.addObjectToScene(l);
    w.addObjectToScene(rect);
    w.addObjectToScene(line);
    w.removeObjectFromScene(rect);
    return a.exec();

}
