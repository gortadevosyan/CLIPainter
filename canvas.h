#ifndef CANVAS_H
#define CANVAS_H

#include <QObject>
#include "basegraphicsitem.h"
#include "commandmessagehandler.h"
class Canvas : public QObject
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent = nullptr){
        handler = new CommandMessageHandler();
        QObject::connect(handler, &CommandMessageHandler::lineRequested, this, &Canvas::on_lineRequested);
        QObject::connect(handler, &CommandMessageHandler::rectangleRequested, this, &Canvas::on_rectangleRequested);
    }
    QString processCommand(QString command){
        return handler->handleCommand(command);
    }
signals:
    void objectAdded(QGraphicsItem *item);
    void objectRemoved(QGraphicsItem *item);
public slots:
    void on_lineRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void on_rectangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
private:
    CommandMessageHandler *handler;
    QHash<QString, BaseGraphicsItem*> map;
};

#endif // CANVAS_H
