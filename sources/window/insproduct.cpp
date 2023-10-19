#include "headers/window/insproduct.h"
#include "ui_insproduct.h"
#include "headers/window/mainapp.h"

InsertProduct::InsertProduct(QWidget *parent) :
    QDialog(parent),
    InsertProductUi(new Ui::InsertProduct)
{
    InsertProductUi->setupUi(this);
    // Hide the "?" button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertProduct::~InsertProduct()
{
    delete InsertProductUi;
}

void InsertProduct::on_pushButton_clicked()
{
    QDate currentDate = QDate::currentDate();
    QString nom = InsertProductUi->nom->text();
    QString marque = InsertProductUi->marque->text();
    QString etat = InsertProductUi->etat->text();
    QString categoriee = InsertProductUi->categorie->text();
    int categorie = categoriee.toInt();
    QString fournisseur = InsertProductUi->fournisseur->text();
    QString admin = InsertProductUi->admin->text();

    query.prepare("INSERT INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie, NomFournisseur, UsernameAdmin) VALUES(:nom, :marque, :etat, :date, :categorie, :fournisseur, :admin)");
    query.bindValue(":nom", nom);
    query.bindValue(":marque", marque);
    query.bindValue(":etat", etat);
    query.bindValue(":date", currentDate);
    query.bindValue(":categorie", categorie);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":admin", admin);
    if(query.exec()){
        this->close();
//        history.showHistory(MainUi->findWidget);
    }else{
        qDebug() << "Insert error : " << query.lastError();
    }
}

