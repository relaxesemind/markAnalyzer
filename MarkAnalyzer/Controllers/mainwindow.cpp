#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Managers/appinitializator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    ui->setupUi(this);
    ui->menuBar->setNativeMenuBar(false);
}
