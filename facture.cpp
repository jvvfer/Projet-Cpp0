#include "facture.h"
#include <QSqlDatabase>
#include <QSqlError>
//setters
void Facture::setID_FACTURE(int n){ID_FACTURE= n;}
void Facture::setDATE_FACTURATION(QString n){DATE_FACTURATION= n;}
void Facture::setMONTANT(int n){MONTANT= n;}
void Facture::setMETHOD_PAIEMENT(QString n){METHOD_PAIEMENT= n;}

//getters

int Facture::get_ID_FACTURE(){return ID_FACTURE;}
QString Facture::get_DATE_FACTURATION() const {return DATE_FACTURATION;}
float Facture::get_MONTANT()  {return MONTANT;}
QString Facture::get_METHOD_PAIEMENT()const{return METHOD_PAIEMENT;}
//CONSTRUCTEUR PAR DEFAUT
Facture::Facture()
{
}
//CONSTRUCTEUR PARAMETRE
Facture::Facture(int ID_FACTURE,QString DATE_FACTURATION,QString METHOD_PAIEMENT,int MONTANT)
{
    this->ID_FACTURE=ID_FACTURE;
    this->DATE_FACTURATION=DATE_FACTURATION;
    this->METHOD_PAIEMENT=METHOD_PAIEMENT;
    this->MONTANT=MONTANT;
}
//CRUD
bool Facture::ajouter()
{
    QSqlQuery query;




        query.prepare("INSERT INTO FACTURE (ID_FACTURE, DATE_FACTURATION,METHOD_PAIEMENT,MONTANT) "
                      "VALUES (:ID_FACTURE, :DATE_FACTURATION, :METHOD_PAIEMENT, :MONTANT)");
        query.bindValue(":ID_FACTURE", ID_FACTURE);
        query.bindValue(":DATE_FACTURATION", DATE_FACTURATION);
        query.bindValue(":MONTANT", MONTANT);
        query.bindValue(":METHOD_PAIEMENT", METHOD_PAIEMENT);






       return query.exec();

}
QSqlQueryModel *Facture::afficher()
{

  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM FACTURE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FACTURE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FACTURATION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("MONTANT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("METHOD_PAIEMENT"));



        return model;
}
bool Facture::modifier(int)
{

QSqlQuery query;

QString id_string=QString::number(ID_FACTURE);
QString montant_string=QString::number(MONTANT);

query.prepare("UPDATE FACTURE SET ID_FACTURE=:ID_FACTURE,DATE_FACTURATION=:DATE_FACTURATION,MONTANT=:MONTANT,METHOD_PAIEMENT=:METHOD_PAIEMENT WHERE ID_FACTURE=:ID_FACTURE;");

query.bindValue(":ID_FACTURE", id_string);
query.bindValue(":DATE_FACTURATION", DATE_FACTURATION);
query.bindValue(":MONTANT", montant_string);
query.bindValue(":METHOD_PAIEMENT", METHOD_PAIEMENT);


return query.exec();

}
bool Facture::idExists(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FACTURE WHERE ID_FACTURE = ?");
    query.addBindValue(id);
    query.exec();
    query.next();
    int count = query.value(0).toInt();
    return count > 0;
}
bool Facture::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
         query.prepare("delete from FACTURE where ID_FACTURE=:id");
         query.bindValue(":id", res);
      return query.exec();
}

