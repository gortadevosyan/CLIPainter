#include "canvas.h"
#include "lineitem.h"
#include "rectangleitem.h"
void Canvas::on_lineRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    LineItem *line = new LineItem(x1, y1, x2, y2, nullptr,name);
    emit(objectAdded(line));
}
void Canvas::on_rectangleRequested(QString name, qreal x1, qreal y1, qreal x2, qreal y2){
    RectangleItem *rect = new RectangleItem(x1, y1, x2, y2, nullptr, name);
    emit(objectAdded(rect));
}
