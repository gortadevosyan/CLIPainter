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
    QString processCommand(QString command);
signals:
    void objectAdded(QGraphicsItem *item);
    void objectRemoved(QGraphicsItem *item);
public slots:
    void on_lineRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void on_rectangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void on_rectangleRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4);
    void on_squareRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4);
    void on_squareRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2);
    void on_triangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3);
private:
    CommandMessageHandler *handler;
    QHash<QString, BaseGraphicsItem*> map;
};

#endif // CANVAS_H
