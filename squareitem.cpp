#include "squareitem.h"

SquareItem::SquareItem(qreal x1, qreal y1, qreal x3, qreal y3, QGraphicsItem *parent, QString name) :
    RectangleItem(x1, y1, (x1 - y1 + x3 + y3)/2, (x1 + y1 - x3 + y3)/2, x3, y3, (x1 + y1 + x3 - y3)/2, (- x1 + y1 + x3 + y3)/2, parent, name){}
SquareItem::~SquareItem(){

}
