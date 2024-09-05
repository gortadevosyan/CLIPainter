#ifndef RECTANGLEITEM_H
#define RECTANGLEITEM_H

#include "polygonitem.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
class RectangleItem : public PolygonItem
{
public:
    RectangleItem(qreal x1, qreal y1, qreal x3, qreal y3, QGraphicsObject *parent = nullptr, QString name = NULL);
    RectangleItem(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4, QGraphicsItem *parent = nullptr, QString name = NULL);
    virtual ~RectangleItem();
};

#endif // RECTANGLEITEM_H
