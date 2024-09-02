#ifndef LINE_H
#define LINE_H
#include "geometriciobject.h"
#include <QObject>
#include <qpoint.h>
class Line : public GeometricObject
{
public:
    Line(int x1, int y1, int x2, int y2);
protected:
    void paintEvent(QPaintEvent* event);
private:
    QPoint *coord_1, *coord_2;
};

#endif // LINE_H
