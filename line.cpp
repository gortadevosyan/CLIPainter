#include "line.h"
#include <QPainter>
Line::Line(int x1, int y1, int x2, int y2, QWidget *parent =  nullptr):
    GeometricObject(parent), line(new QLine(x1, y1, x2, y2))
{
}

void Line::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawLine(*line);
}
Line::~Line() {
    delete line;
}
QPoint Line::getCenter(){
    return line->center();
}
