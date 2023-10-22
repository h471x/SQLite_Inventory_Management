#include "headers/window/insertadmin.h"
#include "ui_insertadmin.h"

InsertAdmin::InsertAdmin(QWidget *parent) :
    QDialog(parent),
    InsertAdminUi(new Ui::InsertAdmin)
{
    InsertAdminUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertAdmin::~InsertAdmin()
{
    delete InsertAdminUi;
}

void InsertAdmin::on_pushButton_clicked() {
    QString username = InsertAdminUi->username->text();
    QString nom = InsertAdminUi->nom->text();
    QString prenom = InsertAdminUi->prenom->text();
    QString adresse = InsertAdminUi->adresse->text();
    QString phone = InsertAdminUi->phone->text();
    QString password = InsertAdminUi->password->text();

    // Check if the password length is greater than or equal to 8
    if (password.length() < 8) {
        InsertAdminUi->password->clear();
        InsertAdminUi->password->setFocus();
        return;
    }

    query.prepare("INSERT OR IGNORE INTO ADMIN(UsernameAdmin, Password, NomAdmin, PrenomAdmin, TelephoneAdmin, AdresseAdmin) VALUES(:usernameadmin, :passwordadmin, :nameadmin, :prenom, :phone, :adresse)");
    query.bindValue(":usernameadmin", username);
    query.bindValue(":passwordadmin", password);
    query.bindValue(":nameadmin", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":phone", phone);
    query.bindValue(":adresse", adresse);

    if (query.exec()) {
        this->close();
    } else {
        qDebug() << "Error : " << query.lastError();
    }
}


