#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QSqlQueryModel>
#include <stdlib.h>
#include <facture.h>
#include <QTableView>


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
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_supp_clicked();

private:
    Ui::MainWindow *ui;
    Facture Ftemp;
};

#endif // MAINWINDOW_H
