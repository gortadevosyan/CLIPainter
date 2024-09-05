#ifndef CANVAS_H
#define CANVAS_H

#include <QObject>
#include "basegraphicsitem.h"
#include "commandmessagehandler.h"
class Canvas : public QObject
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent = nullptr);

signals:
    void objectAdded(QGraphicsItem *item);
    void objectRemoved(QGraphicsItem *item);
private:
    CommandMessageHandler *handler;
    QHash<QString, BaseGraphicsItem*> map;
};

#endif // CANVAS_H
