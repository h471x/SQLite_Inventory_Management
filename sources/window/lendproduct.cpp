#include "headers/window/lendproduct.h"
#include "headers/window/insertlocation.h"
#include "ui_lendproduct.h"

LendProduct::LendProduct(const QString& idmateriel, QWidget *parent) :
    QDialog(parent),
    LendProductUi(new Ui::LendProduct)
{
    LendProductUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    LendProductUi->lend->setText("Lend Product");
    IdMateriel = idmateriel;
    QSqlQuery queryUser("SELECT UsernameUtilisateur from UTILISATEUR");
    queryUser.exec();
    while (queryUser.next()) {
        LendProductUi->username->addItem(queryUser.value(0).toString());
    }

    QSqlQuery queryProduct("SELECT IdMateriel from MATERIEL WHERE Emprunter = 0");
    queryProduct.exec();
    while (queryProduct.next()) {
        LendProductUi->productid->addItem(queryProduct.value(0).toString());
    }

    // Execute a query to retrieve data
   QSqlQuery queryLieu("SELECT NomEmplacement from EMPLACEMENT WHERE Entrepot = 0;"); // Replace with your query
   queryLieu.exec();

   // Populate the QComboBox with data from the query
   while (queryLieu.next()) {
       LendProductUi->location->addItem(queryLieu.value(0).toString());
   }
}

LendProduct::~LendProduct()
{
    delete LendProductUi;
}

void LendProduct::on_lend_clicked()
{      
        QString id = LendProductUi->productid->currentText();
        QString user = LendProductUi->username->currentText();
        QString lieu = LendProductUi->location->currentText();

        QSqlQuery lendQuery;
        lendQuery.prepare("UPDATE MATERIEL SET Emprunter = 1, UsernameUtilisateur= :user, NomEmplacement = :lieu WHERE IdMateriel = :id;");
        lendQuery.bindValue(":user", user);
        lendQuery.bindValue(":lieu", lieu);
        lendQuery.bindValue(":id", id);
        if (lendQuery.exec()) {
            this->close();
        } else {
            qDebug() << "Insert error : " << lendQuery.lastError();
        }
}

