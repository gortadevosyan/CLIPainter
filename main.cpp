#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include "lineitem.h"
#include "basegraphicsitem.h"
#include "squareitem.h"
#include "rectangleitem.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LineItem *line = new LineItem(1, 1, 300, 400, nullptr, "Line_1");
    RectangleItem *rect_2 = new RectangleItem(10, 10, 100, 20, nullptr, "rect_1");
    RectangleItem *rect_3 = new RectangleItem(10, 10, 100, 10, 100, 20, 10, 20, nullptr, "rect_3");
    SquareItem *square = new SquareItem(200, 200, 300, 300, nullptr, "SQUARE!!!!!");
    w.addObjectToScene(square);
    w.addObjectToScene(line);
    w.addObjectToScene(rect_2);
    w.addObjectToScene(rect_3);
    return a.exec();

}
