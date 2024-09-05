#ifndef SQUAREITEM_H
#define SQUAREITEM_H

#include "rectangleitem.h"

class SquareItem : public RectangleItem
{
public:
    SquareItem(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4, QGraphicsItem *parent = nullptr, QString name = NULL) :
        RectangleItem(x1, y1, x2, y2, x3, y3, x4, y4, parent, name){}
    SquareItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = nullptr, QString name = NULL);
    ~SquareItem();
};

#endif // SQUAREITEM_H
