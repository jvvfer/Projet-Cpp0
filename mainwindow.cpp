#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ftmp.afficher());



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_button_clicked()
{

    int id= ui->lineEdit_id->text().toInt();
    QString date = ui->lineEdit_date->text();
    QString method = ui->lineEdit_method->text();
    int montant= ui->lineEdit_montant->text().toInt();

    QString idstr=QString::number(id);
    QString montantstr=QString::number(montant);

    Facture F(id,date ,method,montant);
    if(!idstr.isEmpty() && !date.isEmpty() && !method.isEmpty() )
    {
    F.ajouter();
    ui->tableView->setModel(F.afficher());

}}


void MainWindow::on_modifier_button_clicked()
{
        int idInt = ui->lineEdit_id_2->text().toInt();
        QString date = ui->lineEdit_date_2->text();
        float montantF = ui->lineEdit_montant_2->text().toFloat();
        QString method = ui->lineEdit_method_2->text();

        QSqlQuery query;
        query.prepare("SELECT * FROM FACTURE WHERE ID_FACTURE = ?");
        query.addBindValue(idInt);

        if (query.exec() && query.next()) {
            Facture F(idInt,date,method,montantF);

          bool test =F.modifier(idInt);

            if (test) {
                QMessageBox::information(nullptr, QObject::tr("Modification réussie"),
                                         QObject::tr("Modification effectuée avec succès.\n"
                                                     "Cliquez sur Annuler pour quitter."),
                                         QMessageBox::Cancel);
                ui->tableView->setModel(F.afficher());




            } else {
                QMessageBox::critical(nullptr, QObject::tr("Erreur de modification"),
                                         QObject::tr("La modification a échoué.\n"
                                                     "Cliquez sur Annuler pour quitter."),
                                         QMessageBox::Cancel);
            }
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                     QObject::tr("Le CIN du médecin n'existe pas."),
                                     QMessageBox::Cancel);
        }

}

void MainWindow::on_pushButton_supprimer_clicked()
{





        int id=ui->lineEdit_supprimer->text().toInt();
        if (!Ftmp.idExists(id)) {
            QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                QObject::tr("L'id de la facture n'existe pas.\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
            return;
        }
        else {
            bool test = Ftmp.supprimer(id);
            if(test) {
                QString nom;
                QString prenom;
                int row = 0;
                int rowCount = ui->tableView->model()->rowCount();
                for (; row < rowCount; row++){
                    nom = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString().simplified();
                    prenom = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString().simplified();
                }
                ui->tableView->setModel(Ftmp.afficher());

                QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("Suppression effectuée\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);
            }
            else {
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                          QObject::tr("Suppression non effectuée.\n"
                                                      "Click Cancel to exit."),QMessageBox::Cancel);
            }
        }
    }

