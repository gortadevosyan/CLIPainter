#include "canvas.h"
#include "lineitem.h"
#include "rectangleitem.h"
#include "squareitem.h"
#include "triangleitem.h"

QHash<QString, BaseGraphicsItem*> Canvas::map;

Canvas::Canvas(QObject *parent){
    handler = new CommandMessageHandler();
    QObject::connect(handler, &CommandMessageHandler::lineRequested, this, &Canvas::on_lineRequested);
    QObject::connect(handler, &CommandMessageHandler::rectangleRequested_4, this, &Canvas::on_rectangleRequested_4);
    QObject::connect(handler, &CommandMessageHandler::rectangleRequested, this, &Canvas::on_rectangleRequested);
    QObject::connect(handler, &CommandMessageHandler::triangleRequested, this, &Canvas::on_triangleRequested);
    QObject::connect(handler, &CommandMessageHandler::squareRequested, this, &::Canvas::on_squareRequested);
    QObject::connect(handler, &CommandMessageHandler::squareRequested_4, this, &Canvas::on_squareRequested_4);
    QObject::connect(handler, &CommandMessageHandler::connectRequested, this, &::Canvas::on_connectRequested);
}
bool Canvas::isNameUsed(QString name){
    return map.contains(name);
}
QString Canvas::processCommand(QString command){
    return handler->handleCommand(command);
}
void Canvas::on_lineRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    LineItem *line = new LineItem(x1, y1, x2, y2, nullptr,name);
    map.insert(name, line);
    emit(objectAdded(line));
}
void Canvas::on_rectangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    RectangleItem *rect = new RectangleItem(x1, y1, x2, y2, nullptr, name);
    map.insert(name, rect);
    emit(objectAdded(rect));
}
void Canvas::on_rectangleRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4){
    RectangleItem *rect = new RectangleItem(x1, y1, x2, y2, nullptr, name);
    map.insert(name, rect);
    emit(objectAdded(rect));
}
void Canvas::on_squareRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    SquareItem *square = new SquareItem(x1, y1, x2, y2, nullptr, name);
    map.insert(name, square);
    emit(objectAdded(square));
}
void Canvas::on_squareRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4){
    SquareItem *square = new SquareItem(x1, y1, x2, y2, x3, y3, x4, y4, nullptr, name);
    map.insert(name, square);
    emit(objectAdded(square));
}

void Canvas::on_triangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3){
    TriangleItem *triangle = new TriangleItem(x1, y1, x2, y2, x3, y3, nullptr, name);
    map.insert(name, triangle);
    emit(objectAdded(triangle));
}
void Canvas::on_connectRequested(QString name1, QString name2){
    BaseGraphicsItem *item1 = map.value(name1);
    BaseGraphicsItem *item2 = map.value(name2);
    QPointF center1 = item1->boundingRect().center();
    QPointF center2 = item2->boundingRect().center();
    LineItem *line = new LineItem(center1.x(), center1.y(), center2.x(), center2.y(), nullptr,"");
    emit(objectAdded(line));
}
Canvas::~Canvas(){
    delete handler;
}
