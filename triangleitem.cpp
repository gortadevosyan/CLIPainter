#include "triangleitem.h"

TriangleItem::TriangleItem(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, QGraphicsItem *parent, QString name):
    PolygonItem(name, parent)
{
    //TODO check if all three points are on the same line, throw exception if they are
    QVector<QPointF> points;
    points.push_back(QPointF(x1, y1));
    points.push_back(QPointF(x2, y2));
    points.push_back(QPointF(x3, y3));
    PolygonItem::setPolygon(new QGraphicsPolygonItem(QPolygonF(points)));
}
TriangleItem::~TriangleItem(){}
