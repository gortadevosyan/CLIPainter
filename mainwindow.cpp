#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QVBoxLayout>
#include <qgraphicsview.h>
#include <QGraphicsLineItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
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
}

void MainWindow::addObjectToScene(QGraphicsItem *item){
    scene->addItem(item);
}

void MainWindow::removeObjectFromScene(QGraphicsItem *item){
    scene->removeItem(item);
}

void MainWindow::on_commandLineText_returnPressed()
{
    QString command = ui->commandLineText->text();
    ui->commandLineText->clear();
    ui->logTextEdit->append(command);
}



