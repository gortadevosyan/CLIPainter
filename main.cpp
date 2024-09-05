#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include "lineitem.h"
#include "rectangleitem.h"
#include "squareitem.h"
#include "triangleitem.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LineItem *line = new LineItem(1, 1, 300, 400, nullptr, "Line_1");
    RectangleItem *rect_2 = new RectangleItem(100, 100, 200, 200, nullptr, "rect_1");
    RectangleItem *rect_3 = new RectangleItem(0, 0, 100, 0, 100, 100, 0, 100, nullptr, "rect_3");
    SquareItem *square = new SquareItem(200, 200, 300, 300, nullptr, "SQUARE!!!!!");
    TriangleItem *tri = new TriangleItem(40, 50, 82, 89, 409, 302, nullptr, "triangle_1");
    w.addObjectToScene(tri);
    w.addObjectToScene(square);
    w.addObjectToScene(line);
    w.addObjectToScene(rect_2);
    w.addObjectToScene(rect_3);
    return a.exec();
}
