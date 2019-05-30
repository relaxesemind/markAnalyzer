#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QStringList>
#include <QStandardPaths>
#include <QDebug>

#include "core.h"
#include "Common/customtypes.h"

#include "Managers/markscalculatetask.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    threadPool(new QThreadPool(this))
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

void MainWindow::on_pushButton_5_clicked()//MAIN ACTION
{
    MarksCalculateTask *task = new MarksCalculateTask();

    connect(task,&MarksCalculateTask::isRunning,this,[this](bool currentlyRunning)
        {
            if (currentlyRunning)
            {
                spinner = new WaitingSpinnerWidget(ui->imageView, Qt::ApplicationModal, true);
                spinner->setRoundness(70.0);
                spinner->setMinimumTrailOpacity(15.0);
                spinner->setTrailFadePercentage(70.0);
                spinner->setNumberOfLines(12);
                spinner->setLineLength(12);
                spinner->setLineWidth(4);
                spinner->setInnerRadius(10);
                spinner->setRevolutionsPerSecond(1);
                spinner->start();
            }
            else if (spinner != nullptr)
            {
                spinner->stop();

                delete spinner;
                spinner = nullptr;
            }
        });

    connect(task,&MarksCalculateTask::isDone,this,[](bool status)
      {
          if (!status)
          {
              return;
          }

          // update UI
      });

    threadPool->start(task);
}















