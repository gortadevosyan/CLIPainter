#ifndef POLYGONITEM_H
#define POLYGONITEM_H

#include "basegraphicsitem.h"

class PolygonItem : public BaseGraphicsItem
{
public:
    PolygonItem(QString name = NULL, QGraphicsItem *parent = nullptr) :
        BaseGraphicsItem(name, parent){}
    virtual ~PolygonItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        poly->setBrush(Qt::blue);
        poly->paint(painter, option, widget);
        BaseGraphicsItem::paint(painter, option, widget);
    }
    virtual QRectF boundingRect() const override{
        return poly->boundingRect();
    }
private:
    QGraphicsPolygonItem *poly;
};

#endif // POLYGONITEM_H
