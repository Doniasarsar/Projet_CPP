#include "facture.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Facture::Facture()
{
id_f=0; date_f=""; ttc_f="";
}
Facture::Facture(int id_f,QString date_f,QString ttc_f){
    this->id_f=id_f;
    this->date_f=date_f;
    this->ttc_f=ttc_f;

}
int Facture::getid_f(){
    return id_f;
}
QString Facture::getdate_f(){
    return date_f;
}
QString Facture::getttc_f(){
    return ttc_f;
}
void Facture::setid_f(int id_f){
    this->id_f=id_f;
}
void Facture::setdate_f(QString date_f){
    this->date_f=date_f;
}
void Facture::setttc_f(QString ttc_f){
    this->ttc_f=ttc_f;
}
bool Facture::ajouter(){
    bool test=true;
    QSqlQuery query;
    QString id_string= QString::number(id_f);
          query.prepare("INSERT INTO FACTURES (ID_F, DATE_F, TTC_F) "
                        "VALUES (:id_f, :forename, :surname)");
          query.bindValue(":id_f", id_string);
          query.bindValue(":forename", date_f);
          query.bindValue(":surname", ttc_f);
          query.exec();
    return test;
}
QSqlQueryModel *Facture::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM FACTURES");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de facture"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total TTC"));          

          return model;
}
bool Facture::supprimer(int id_f){
    QSqlQuery query;

    query.prepare("DELETE FROM FACTURES WHERE ID_F = :id_f ");
    query.bindValue(":id_f", id_f);
    return    query.exec();
}
