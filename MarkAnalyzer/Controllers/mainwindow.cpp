#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStringList>
#include <QStandardPaths>
#include <QDebug>

#include "core.h"
#include "Common/customtypes.h"

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

    auto& marks = StaticStorage::shared().marks;
    for (auto mark : marks)
    {
        QString name = mark.get()->markName();
        ui->listWidget->addItem(name);
    }
}

void MainWindow::loadNormalImages()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Выберите папку с изображениями"),
                                                     QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                     QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (path.isEmpty())
    {
        return;
    }

    qDebug() << path;

    Core::shared().loadImagesFromFolderPath(path,ImageType::notMelanoma);
}

void MainWindow::loadBadImages()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Выберите папку с изображениями"),
                                                     QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                     QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (path.isEmpty())
    {
        return;
    }

    qDebug() << path;

    Core::shared().loadImagesFromFolderPath(path,ImageType::melanoma);
}

void MainWindow::on_pushButton_clicked()//addNonMelanomaImages
{
    loadNormalImages();
}

void MainWindow::on_pushButton_3_clicked()
{
    loadBadImages();
}

void MainWindow::on_action_triggered()
{
    loadBadImages();
}

void MainWindow::on_action_2_triggered()
{
    loadNormalImages();
}
