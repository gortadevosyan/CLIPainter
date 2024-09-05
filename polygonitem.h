#ifndef POLYGONITEM_H
#define POLYGONITEM_H

#include "basegraphicsitem.h"

class PolygonItem : public BaseGraphicsItem
{
public:
    PolygonItem(QString name, QGraphicsItem *parent):
        BaseGraphicsItem(name, parent){};
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        poly->setBrush(Qt::blue);
        poly->paint(painter, option, widget);
        BaseGraphicsItem::paint(painter, option, widget);
    }
    QRectF boundingRect() const override{
        return poly->boundingRect();
    }
    virtual ~PolygonItem(){
        delete poly;
    }
protected:
    void setPolygon(QGraphicsPolygonItem *newPoly){
        poly = newPoly;
    }
private:
    QGraphicsPolygonItem *poly;
};

#endif // POLYGONITEM_H
