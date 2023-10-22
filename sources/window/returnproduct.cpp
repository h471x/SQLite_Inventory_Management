#include "headers/window/returnproduct.h"
#include "headers/window/insertlocation.h"
#include "headers/database/init/dbetat.h"
#include "ui_returnproduct.h"

ReturnProduct::ReturnProduct(QWidget *parent) :
    QDialog(parent),
    ReturnProductUi(new Ui::ReturnProduct)
{
    ReturnProductUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    QSqlQuery queryUser("SELECT IdMateriel from MATERIEL where Emprunter = 1");
    queryUser.exec();
    while (queryUser.next()) {
        ReturnProductUi->id->addItem(queryUser.value(0).toString());
    }

    // Execute a query to retrieve data
   QSqlQuery queryLieu("SELECT NomEmplacement from EMPLACEMENT WHERE Entrepot = 1;"); // Replace with your query
   queryLieu.exec();

   // Populate the QComboBox with data from the query
   while (queryLieu.next()) {
       ReturnProductUi->location->addItem(queryLieu.value(0).toString());
   }

   // Execute a query to retrieve data
   QSqlQuery queryEtat("SELECT NomEtat from ETAT;"); // Replace with your query
   queryEtat.exec();

   // Populate the QComboBox with data from the query
   while (queryEtat.next()) {
       ReturnProductUi->etat->addItem(queryEtat.value(0).toString());
   }
}

ReturnProduct::~ReturnProduct()
{
    delete ReturnProductUi;
}

void ReturnProduct::on_returnProduct_clicked()
{
    QString id = ReturnProductUi->id->currentText();
    QString location = ReturnProductUi->location->currentText();
    QString etat = ReturnProductUi->etat->currentText();

    QSqlQuery returnQuery;
    returnQuery.prepare("UPDATE MATERIEL SET Emprunter = 0, NomEmplacement = :location, NomEtat = :etat WHERE IdMateriel = :id;");
    returnQuery.bindValue(":id", id);
    returnQuery.bindValue(":location", location);
    returnQuery.bindValue(":etat", etat);
    if (returnQuery.exec()) {
        this->close();
    } else {
        qDebug() << "Insert error : " << returnQuery.lastError();
    }
}

