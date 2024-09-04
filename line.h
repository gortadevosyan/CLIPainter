#ifndef LINE_H
#define LINE_H
#include "geometriciobject.h"
#include <QGraphicsObject>
class Line : public GeometricObject
{
public:
    Line(int x1, int y1, int x2, int y2, QWidget *parent);
    ~Line();
    QPoint getCenter() override;
protected:
    void paintEvent(QPaintEvent* event) override;
private:
    const QLine *line;
};

#endif // LINE_H
