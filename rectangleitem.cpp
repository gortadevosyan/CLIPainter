#include "rectangleitem.h"

RectangleItem::RectangleItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsObject *parent, QString name):
    BaseGraphicsItem(name, parent)
{
    qreal width = abs(x2-x1);
    qreal height = abs(y2-y1);
    qreal topLeftX, topLeftY;
    //top left corner corresponds to (0,0), +x direction is to the right, -y direction is downwards
    if(x1<x2 && (x1==x2 && y1<y2)){
        topLeftX = x1, topLeftY = y1;
    }
    else {
        topLeftX = x2, topLeftY = y2;
    }
    //TODO: Throw INVALID INPUT exceptio or some error message because the two points coincide
    QRectF rect = QRectF(topLeftX, topLeftY, width, height);
    poly = new QGraphicsPolygonItem(rect, parent);
}

RectangleItem::RectangleItem(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4, QGraphicsItem *parent, QString name):
    BaseGraphicsItem(name, parent)
{
    qreal diagonal1, diagonal2;
    diagonal1 = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
    diagonal2 = (x2-x4)*(x2-x4) + (y2-y4)*(y2-y4);
    if(diagonal1 != diagonal2){
        //TODO: Throw Invalid Input exception or error message to the logs
    }
    QVector<QPointF> points;
    points.push_back(QPointF(x1, y1));
    points.push_back(QPointF(x2, y2));
    points.push_back(QPointF(x3, y3));
    points.push_back(QPointF(x4, y4));
    poly = new QGraphicsPolygonItem(QPolygonF(points));
}
void RectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    poly->setBrush(Qt::blue);
    poly->paint(painter, option, widget);
    BaseGraphicsItem::paint(painter, option, widget);
}
QRectF RectangleItem::boundingRect() const{
    return poly->boundingRect();
}

RectangleItem::~RectangleItem(){
    delete poly;
}
