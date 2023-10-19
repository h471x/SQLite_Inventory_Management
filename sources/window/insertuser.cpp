#include "headers/window/insertuser.h"
#include "ui_insertuser.h"

InsertUser::InsertUser(QWidget *parent) :
    QDialog(parent),
    InsertUserUi(new Ui::InsertUser)
{
    InsertUserUi->setupUi(this);
    // Hide the "?" button
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertUser::~InsertUser()
{
    delete InsertUserUi;
}

void InsertUser::on_pushButton_clicked()
{
    QString username = InsertUserUi->username->text();
    QString nom = InsertUserUi->nom->text();
    QString prenom = InsertUserUi->prenom->text();
    QString adresse = InsertUserUi->adresse->text();
    QString telephone = InsertUserUi->telephone->text();

    if (!username.isEmpty() && !nom.isEmpty() && !prenom.isEmpty() && !adresse.isEmpty() && !telephone.isEmpty())
    {
        bool isNumeric;
        telephone.toInt(&isNumeric);

        if (isNumeric && telephone.length() == 10) {
            query.prepare("INSERT INTO UTILISATEUR(UsernameUtilisateur, NomUtilisateur, PrenomUtilisateur, AdresseUtilisateur, TelephoneUtilisateur) VALUES(:username, :nom, :prenom, :adresse, :telephone);");
            query.bindValue(":username", username);
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
            query.bindValue(":adresse", adresse);
            query.bindValue(":telephone", telephone);

            if(query.exec()){
                this->close();
            } else {
                qDebug() << "Insert error: " << query.lastError();
            }
        } else {
            // Handle the case where telephone is not a 10-digit integer
            QMessageBox::critical(this, "Error", "Telephone must be a 10-digit number.");
        }
    }
    else
    {
//        qDebug() << "Missed value";
        // Handle the case where required fields are missing
        QMessageBox::warning(this, "Missing Values", "Please fill in all the required fields.");
    }
}

