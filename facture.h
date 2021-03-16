#ifndef FACTURE_H
#define FACTURE_H
#include <QString>

class Facture
{
public:
    Facture();
    Facture(int,QString,QString);
    int getid_f();
    QString getdate_f();
    QString getttc_f();
    void setid_f(int);
    void setdate_f(QString);
    void setttc_f(QString);
    bool ajouter();
private:
    int id_f;
    QString date_f,ttc_f;
};

#endif // FACTURE_H
