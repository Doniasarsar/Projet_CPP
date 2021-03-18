#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include <QMessageBox>
#include <QPixmap>
#include <QIntValidator>
#include <QTableView>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tab_fact->setModel(Ftemp.afficher());

    /*/////////////////////////////AJOUTTER IMAGE/////////////////////////////////////*/
    QPixmap pix("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProj/img/ajout.png");
    ui->label_4->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap pix_sup("C:/Users/waelk/OneDrive/Bureau/C++/PROJET/MyProj/img/supprime.png");
    ui->label_5->setPixmap(pix_sup.scaled(100,100,Qt::KeepAspectRatio));
    /*/////////////////////////////////////////////////////////////////////////////*/
    /*////////////////////////CONTROLE DE SAISIE///////////////////////////////////*/
    ui->le_id_f->setValidator( new QIntValidator(0, 999999999, this));
    /*/////////////////////////////////////////////////////////////////////////////*/
    ui->tab_fact->setModel(Ftemp.afficher());

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
        ui->tab_fact->setModel(Ftemp.afficher());


    }else{
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->tab_fact->setModel(Ftemp.afficher());

}

void MainWindow::on_supp_clicked()
{
    int id_f=ui->le_supp_f->text().toInt();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer cette facture?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=Ftemp.supprimer(id_f);
          if(test)
          {
              ui->tab_fact->setModel(Ftemp.afficher());
              QMessageBox::information(nullptr,"Suppression","Facture supprimé");

          }
      }
}
