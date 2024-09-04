#include "rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2, QWidget* parent) :
    GeometricObject(parent)
{
    if(x1 < x2 || (x1 == x2 && y1>y2)){
        topLeft = new QPoint(x1, y1);
        bottomRight = new  QPoint(x2, y2);
    }
    else{
        topLeft = new QPoint(x2, y2);
        bottomRight = new QPoint(x1, y1);
    }
    rectangle = new QRect(*topLeft, *bottomRight);
}
Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, QWidget* parent){

}
Rectangle::~Rectangle(){
    delete rectangle;
    delete topLeft;
    delete bottomRight;
}
QPoint Rectangle::getCenter(){
    return rectangle->center();
}
void Rectangle::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawRect(*rectangle);
}
