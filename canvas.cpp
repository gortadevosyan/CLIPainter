#include "canvas.h"
#include "lineitem.h"
#include "rectangleitem.h"
#include "squareitem.h"
#include "triangleitem.h"
Canvas::Canvas(QObject *parent){
    handler = new CommandMessageHandler();
    QObject::connect(handler, &CommandMessageHandler::lineRequested, this, &Canvas::on_lineRequested);
    QObject::connect(handler, &CommandMessageHandler::rectangleRequested_4, this, &Canvas::on_rectangleRequested_4);
    QObject::connect(handler, &CommandMessageHandler::rectangleRequested, this, &Canvas::on_rectangleRequested);
    QObject::connect(handler, &CommandMessageHandler::triangleRequested, this, &Canvas::on_triangleRequested);
    QObject::connect(handler, &CommandMessageHandler::squareRequested, this, &::Canvas::on_squareRequested);
    QObject::connect(handler, &CommandMessageHandler::squareRequested_4, this, &Canvas::on_squareRequested_4);
}
QString Canvas::processCommand(QString command){
    return handler->handleCommand(command);
}
void Canvas::on_lineRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    LineItem *line = new LineItem(x1, y1, x2, y2, nullptr,name);
    emit(objectAdded(line));
}
void Canvas::on_rectangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    RectangleItem *rect = new RectangleItem(x1, y1, x2, y2, nullptr, name);
    emit(objectAdded(rect));
}
void Canvas::on_rectangleRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4){
    RectangleItem *rect = new RectangleItem(x1, y1, x2, y2, nullptr, name);
    emit(objectAdded(rect));
}
void Canvas::on_squareRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    SquareItem *square = new SquareItem(x1, y1, x2, y2, nullptr, name);
    emit(objectAdded(square));
}
void Canvas::on_squareRequested_4(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3, qreal x4, qreal y4){
    SquareItem *square = new SquareItem(x1, y1, x2, y2, x3, y3, x4, y4, nullptr, name);
    emit(objectAdded(square));
}

void Canvas::on_triangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3){
    TriangleItem *triangle = new TriangleItem(x1, y1, x2, y2, x3, y3, nullptr, name);
    emit(objectAdded(triangle));
}
