#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinscale->setValue(this->ui->renderarea->scale());
    this->ui->spinstep->setValue(this->ui->renderarea->stepCount());
    this->ui->spininterval->setValue(this->ui->renderarea->intervalLength());
    this->ui->horizontalSlider->setValue(this->ui->renderarea->penWidth());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->renderarea->repaint();
    this->ui->spinscale->setValue(this->ui->renderarea->scale());
    this->ui->spinstep->setValue(this->ui->renderarea->stepCount());
    this->ui->spininterval->setValue(this->ui->renderarea->intervalLength());
    this->ui->horizontalSlider->setValue(this->ui->renderarea->penWidth());
}
void MainWindow::on_btnastroid_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Astroid);
    update_ui();
}


void MainWindow::on_btnhuygens_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Huygenscycloid);
    update_ui();
}


void MainWindow::on_btncycloid_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Cycloid);
    this->ui->renderarea->repaint();
    update_ui();
}


void MainWindow::on_btnhypocycloid_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Hypocycloid);
    update_ui();
}



void MainWindow::on_btnline_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Line);
    update_ui();
}


void MainWindow::on_btncircle_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Circle);
    update_ui();
}


void MainWindow::on_btnellipse_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Ellipse);
    update_ui();
}


void MainWindow::on_btnfancy_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Fancycurve);
    update_ui();
}


void MainWindow::on_btnlucky_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Luckystarfish);
    update_ui();
}


void MainWindow::on_btncloud_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Cloud);
    update_ui();
}


void MainWindow::on_btninvertedcloud_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Invertedcloud);
    update_ui();
}


void MainWindow::on_spinscale_valueChanged(double scale)
{
    this->ui->renderarea->setScale(scale);
    this->ui->renderarea->repaint();
}


void MainWindow::on_spinstep_valueChanged(double stepCount)
{
    this->ui->renderarea->setStepCount(stepCount);
    this->ui->renderarea->repaint();
}


void MainWindow::on_spininterval_valueChanged(double interval)
{
    this->ui->renderarea->setIntervalLength(interval);
    this->ui->renderarea->repaint();
}


void MainWindow::on_btnbackcolor_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderarea->backgroundColor(),this,"Select Background Color");
    ui->renderarea->setBackgroundColor(color);
    this->ui->renderarea->repaint();

}


void MainWindow::on_btnshapecolor_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderarea->shapeColor(),this,"Select Shape Color");
    ui->renderarea->setShapeColor(color);
    this->ui->renderarea->repaint();
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->ui->renderarea->setPenWidth(value);
    this->ui->renderarea->repaint();
}

