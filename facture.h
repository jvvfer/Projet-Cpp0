#ifndef FACTURE_H
#define FACTURE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Facture
{
    QString METHOD_PAIEMENT,DATE_FACTURATION;
    int ID_FACTURE;
    int MONTANT;
public:

    Facture();
    Facture(int, QString, QString,int);
    void setID_FACTURE(int n);
    void setMETHOD_PAIEMENT(QString n);
    void setDATE_FACTURATION(QString n);
    void setMONTANT(int n);

    //Getters
    int get_ID_FACTURE();
    QString get_METHOD_PAIEMENT() const;
    QString get_DATE_FACTURATION() const ;
    float get_MONTANT();
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
     bool idExists(int id) ;
    QSqlQueryModel * afficher();

};

#endif // FACTURE_H
