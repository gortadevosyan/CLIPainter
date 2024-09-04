#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "geometriciobject.h"
#include <QPainter>
class Rectangle : public GeometricObject
{
public:
    Rectangle(int x1, int y1, int x2, int y2, QWidget* parent = nullptr);
    Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, QWidget* parent = nullptr);
    ~Rectangle();
    QPoint getCenter() override;
protected:
    void paintEvent(QPaintEvent* event) override;
private:
    const QRect *rectangle;
    const QPoint *topLeft, *bottomRight;
};

#endif // RECTANGLE_H
