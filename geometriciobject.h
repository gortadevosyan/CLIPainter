#ifndef GEOMETRICIOBJECT_H
#define GEOMETRICIOBJECT_H
#include <QWidget>
#include <QObject>

class GeometricObject : public QWidget
{
    Q_OBJECT

public:
    explicit GeometricObject(QWidget *parent = nullptr){};
    void setCenter(QPoint newCenter){ *center = newCenter;}
    virtual QPoint getCenter() = 0;
protected:
    virtual void paintEvent(QPaintEvent* event) = 0;
signals:
private:
    QPoint *center;
};

#endif // GEOMETRICIOBJECT_H
