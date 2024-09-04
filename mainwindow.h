#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addObjectToScene(QGraphicsItem *item);
    void removeObjectFromScene(QGraphicsItem *item);
private slots:
    void on_commandLineText_returnPressed();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QWidget *cWidget;
    QVBoxLayout *layout;
};
#endif // MAINWINDOW_H
