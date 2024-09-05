#ifndef TRIANGLEITEM_H
#define TRIANGLEITEM_H

#include "polygonitem.h"

class TriangleItem : public PolygonItem
{
public:
    TriangleItem(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, QGraphicsItem *parent = nullptr, QString name = NULL);
    virtual ~TriangleItem();
};

#endif // TRIANGLEITEM_H
