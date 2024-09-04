#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include "lineitem.h"
#include "basegraphicsitem.h"
#include "rectangleitem.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LineItem *line = new LineItem(1, 1, 300, 400, nullptr, "Line_1");
    QGraphicsLineItem *l = new QGraphicsLineItem(400, 400, 10, -100);
    QGraphicsRectItem *rect = new QGraphicsRectItem(100, 100, 50, 50);
    RectangleItem *rect_2 = new RectangleItem(100, 100, 200, 200, nullptr, "rect_2");
    w.addObjectToScene(l);
    w.addObjectToScene(rect);
    w.addObjectToScene(line);
    w.removeObjectFromScene(rect);
    w.addObjectToScene(rect_2);
    return a.exec();

}
