#ifndef BASEGRAPHICSITEM_H
#define BASEGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPainter>

class BaseGraphicsItem : public QGraphicsItem
{
public:
    BaseGraphicsItem(QString str = NULL, QGraphicsItem *parent = nullptr):
        QGraphicsItem(parent)
    {
        name = str;
    };
    void setName(QString str){this->name = str;}
    QString getName(){return this->name;}
    virtual ~BaseGraphicsItem(){};
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        painter->setPen(Qt::black);
        painter->setFont(QFont("Arial", 10));
        painter->drawText(boundingRect(), Qt::AlignCenter | Qt::AlignCenter, name);
    }
    void fill(QPainter *painter){
        painter->setBrush(Qt::blue);
    }
private:
    QString name;
};

#endif // BASEGRAPHICSITEM_H
