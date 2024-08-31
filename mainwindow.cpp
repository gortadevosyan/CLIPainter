#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLineText_returnPressed()
{
    QString command = ui->commandLineText->text();
    ui->commandLineText->clear();
    ui->logTextEdit->append(command);
}

