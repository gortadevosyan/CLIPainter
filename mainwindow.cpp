#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QVBoxLayout>
#include <qgraphicsview.h>
#include <QGraphicsLineItem>
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    canvas = new Canvas(this);
    QObject::connect(canvas, &Canvas::objectAdded, this, &MainWindow::on_objectAddedToScene);
    QObject::connect(canvas, &Canvas::objectRemoved, this, &MainWindow::on_objecRemovedFromScene);
    ui->graphicsView->setScene(this->scene);
    cWidget = new QWidget();
    layout = new QVBoxLayout(cWidget);
    ui->commandLineText->setPlaceholderText("Command Console");
    layout->addWidget(ui->graphicsView);
    layout->addWidget(ui->commandLineText);
    layout->addWidget(ui->logTextEdit);
    setCentralWidget(cWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete layout;
    delete cWidget;
    delete canvas;
}

void MainWindow::addObjectToScene(QGraphicsItem *item){
    scene->addItem(item);
}

void MainWindow::removeObjectFromScene(QGraphicsItem *item){
    scene->removeItem(item);
}

bool isCommandMessageValid(const QString &message){
    QString temp = message;
    QStringList list = temp.split("-");
    if(list.first()=="create")
        return true;
    else return false;
}

void MainWindow::on_commandLineText_returnPressed()
{
    QString command = ui->commandLineText->text();
    ui->commandLineText->clear();
    ui->logTextEdit->append(canvas->processCommand(command));
}

//TODO remove the obsolete functions, keep the slots only
void MainWindow::on_objectAddedToScene(QGraphicsItem *item){
    addObjectToScene(item);
}
void MainWindow::on_objecRemovedFromScene(QGraphicsItem *item){
    removeObjectFromScene(item);
}
