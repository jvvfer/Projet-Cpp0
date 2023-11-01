#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "facture.h"
#include <QMainWindow>
#include "ui_mainwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajout_button_clicked();

    void on_modifier_button_clicked();

    void on_pushButton_supprimer_clicked();

private:
    Ui::MainWindow *ui;
     Facture Ftmp;
};

#endif // MAINWINDOW_H
