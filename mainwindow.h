#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnastroid_clicked();

    void on_btnhuygens_clicked();

    void on_btncycloid_clicked();

    void on_btnhypocycloid_clicked();

    void on_btnline_clicked();

    void on_spinscale_valueChanged(double scale);

    void on_spinstep_valueChanged(double step);

    void on_spininterval_valueChanged(double interval);

    void on_btnbackcolor_clicked();

    void on_btnshapecolor_clicked();

    void on_btncircle_clicked();

    void on_btnellipse_clicked();

    void on_btnfancy_clicked();

    void on_btnlucky_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_btncloud_clicked();

    void on_btninvertedcloud_clicked();

private:
    void update_ui();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
