#include "headers/window/insproduct.h"
#include "headers/database/init/dbcategory.h"
#include "ui_insproduct.h"
#include "headers/window/mainapp.h"

InsertProduct::InsertProduct(QWidget *parent) :
    QDialog(parent),
    InsertProductUi(new Ui::InsertProduct)
{
    InsertProductUi->setupUi(this);
    // Hide the "?" button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    // Execute a query to retrieve data
    QSqlQuery queryCategorie("SELECT NomCategorie from CATEGORIE"); // Replace with your query
    queryCategorie.exec();

    // Populate the QComboBox with data from the query
    while (queryCategorie.next()) {
        InsertProductUi->categorie->addItem(queryCategorie.value(0).toString());
    }

    // Execute a query to retrieve data
    QSqlQuery queryFournisseur("SELECT NomFournisseur from FOURNISSEUR"); // Replace with your query
    queryFournisseur.exec();

    // Populate the QComboBox with data from the query
    while (queryFournisseur.next()) {
        InsertProductUi->fournisseur->addItem(queryFournisseur.value(0).toString());
    }
}

InsertProduct::~InsertProduct()
{
    delete InsertProductUi;
}

void InsertProduct::on_pushButton_clicked()
{
    QDate date = QDate::currentDate();
    QString currentDate = date.toString("dd/MM/yyyy");
    QString nom = InsertProductUi->nom->text();
    QString marque = InsertProductUi->marque->text();
    QString etat = InsertProductUi->etat->currentText();
    QString categorieNom = InsertProductUi->categorie->currentText();
    QString fournisseur = InsertProductUi->fournisseur->currentText();
    QString admin = InsertProductUi->admin->text();
    QString password = InsertProductUi->passwordadmin->text();

    // Check if any of the fields are empty
    if (nom.isEmpty() || marque.isEmpty() || etat.isEmpty() || categorieNom.isEmpty() || fournisseur.isEmpty() || admin.isEmpty() || password.isEmpty()) {
//        qDebug() << "One or more fields are empty. Insertion canceled.";
        // Display an error message or handle the case of empty fields as needed

        // Clear the fields that caused the error
        if (nom.isEmpty()) {
            InsertProductUi->nom->clear();
        }
        if (marque.isEmpty()) {
            InsertProductUi->marque->clear();
        }
        if (admin.isEmpty()) {
            InsertProductUi->admin->clear();
        }
        if (password.isEmpty()) {
            InsertProductUi->passwordadmin->clear();
        }
    } else {
        // Query to fetch the IdCategorie based on the selected NomCategorie
        QSqlQuery categorieQuery;
        categorieQuery.prepare("SELECT IdCategorie FROM CATEGORIE WHERE NomCategorie = :categorieNom");
        categorieQuery.bindValue(":categorieNom", categorieNom);

        if (categorieQuery.exec() && categorieQuery.next()) {
            // Retrieve the IdCategorie from the query result
            int categorie = categorieQuery.value(0).toInt();

            // Query to check if the provided admin and password match in the ADMIN table
            QSqlQuery adminQuery;
            adminQuery.prepare("SELECT COUNT(*) FROM ADMIN WHERE UserNameAdmin = :admin AND Password = :password");
            adminQuery.bindValue(":admin", admin);
            adminQuery.bindValue(":password", password);

            if (adminQuery.exec() && adminQuery.next() && adminQuery.value(0).toInt() == 1) {
                // Insert data into the MATERIEL table
                QSqlQuery query;
                query.prepare("INSERT INTO MATERIEL(NomMateriel, Marque, DEnregistrement, IdCategorie, Etat, NomFournisseur, UsernameAdmin) VALUES(:nom, :marque, :date, :categorie, :etat, :fournisseur, :admin)");
                query.bindValue(":nom", nom);
                query.bindValue(":marque", marque);
                query.bindValue(":date", currentDate);
                query.bindValue(":categorie", categorie);
                query.bindValue(":etat", etat);
                query.bindValue(":fournisseur", fournisseur);
                query.bindValue(":admin", admin);

                if (query.exec()) {
                    this->close();
                    // Insert was successful
                    // history.showHistory(MainUi->findWidget);
                } else {
//                    qDebug() << "Insert error : " << query.lastError();
                }
            } else {
//                qDebug() << "Admin and password do not match in the ADMIN table or there are multiple matches.";
                // Display an error message or handle the case of mismatched admin and password as needed
                // Clear the fields that caused the error
                InsertProductUi->admin->clear();
                InsertProductUi->passwordadmin->clear();
                InsertProductUi->admin->setFocus();
            }
        } else {
//            qDebug() << "Failed to fetch IdCategorie: " << categorieQuery.lastError();
        }
    }
}




