#ifndef LINEITEM_H
#define LINEITEM_H

#include "basegraphicsitem.h"

#include <QGraphicsLineItem>
#include <qpainter.h>
class LineItem : public BaseGraphicsItem
{
public:
    LineItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsObject *parent = nullptr, QString name = NULL):
        BaseGraphicsItem(name, parent)
    {
        line = new QGraphicsLineItem(x1, y1, x2, y2, parent);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        line->paint(painter, option, widget);
        BaseGraphicsItem::paint(painter, option, widget);
    }
    QRectF boundingRect() const override {
        return line->boundingRect();
    }
    ~LineItem(){
        delete line;
    }
private:
    QGraphicsLineItem *line;
};

#endif // LINEITEM_H
