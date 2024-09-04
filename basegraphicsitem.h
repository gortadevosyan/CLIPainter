#ifndef BASEGRAPHICSITEM_H
#define BASEGRAPHICSITEM_H

#include <QGraphicsItem>
#include <qpainter.h>

class BaseGraphicsItem : public QGraphicsItem
{
public:
    BaseGraphicsItem(QString str = NULL):
        QGraphicsItem()
    {
        name = str;
    };
    void setName(QString str){this->name = str;}
    QString getName(){return this->name;}
    virtual ~BaseGraphicsItem(){};
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        painter->setPen(Qt::black);
        painter->setBrush(Qt::blue);
        painter->setFont(QFont());
        painter->drawText(boundingRect(), Qt::AlignLeft | Qt::AlignTop, name);
    }
private:
    QString name;
};

#endif // BASEGRAPHICSITEM_H
