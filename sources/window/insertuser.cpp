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
        query.prepare("INSERT INTO UTILISATEUR(UsernameUtilisateur, NomUtilisateur, PrenomUtilisateur, AdresseUtilisateur, TelephoneUtilisateur) VALUES(:username, :nom, :prenom, :adresse, :telephone);");
        query.bindValue(":username", username);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":adresse", adresse);
        query.bindValue(":telephone", telephone);
        if(query.exec()){
             this->close();
        }else{
            qDebug() << "Insert error : " << query.lastError();
        }
    }
    else
    {
        qDebug() << " Missed value ";
    }


}

