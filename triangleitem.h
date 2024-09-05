#ifndef TRIANGLEITEM_H
#define TRIANGLEITEM_H

#include "basegraphicsitem.h"

class TriangleItem : public BaseGraphicsItem
{
public:
    TriangleItem(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, QGraphicsItem *parent = nullptr, QString name = NULL);
    ~TriangleItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual QRectF boundingRect() const override;
private:
    QGraphicsPolygonItem *poly;
};

#endif // TRIANGLEITEM_H
