#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include <QMessageBox>
#include <QPixmap>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    /*/////////////////////////////AJOUTTER IMAGE/////////////////////////////////////*/
    QPixmap pix("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProj/img/ajout.png");
    ui->label_4->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    /*/////////////////////////////////////////////////////////////////////////////*/
    /*////////////////////////CONTROLE DE SAISIE///////////////////////////////////*/
    ui->le_id_f->setValidator( new QIntValidator(0, 999999999, this));
    /*/////////////////////////////////////////////////////////////////////////////*/
    ui->tab_fact->setModel(F.afficher());

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id_f=ui->le_id_f->text().toInt();
    QString date_f=ui->le_date_f->text();
    QString ttc_f=ui->le_ttc_f->text();

    Facture F(id_f,date_f,ttc_f);

    bool test=F.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->tab_fact->setModel(F.afficher());

}
