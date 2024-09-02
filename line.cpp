#include "line.h"

Line::Line(int x1, int y1, int x2, int y2) {
    *coord_1 = QPoint(x1, y1);
    *coord_2 = QPoint(x2, y2);
}

void Line::paintEvent(QPaintEvent* event){

}
