#include "headers/window/insertlocation.h"
#include "ui_insertlocation.h"

InsertLocation::InsertLocation(QWidget *parent) :
    QDialog(parent),
    InsertLocationUi(new Ui::InsertLocation)
{
    InsertLocationUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertLocation::~InsertLocation()
{
    delete InsertLocationUi;
}

void InsertLocation::on_insertLocation_clicked()
{
    QString location = InsertLocationUi->location->text();
    QString entrepot = InsertLocationUi->entrepot->currentText();

    query.prepare("INSERT OR IGNORE INTO EMPLACEMENT(NomEmplacement, Entrepot) VALUES(:location, :entrepot)");
    query.bindValue(":location", location);

    if(entrepot == "Oui"){
        query.bindValue(":entrepot", 1);
    }else if(entrepot == "Non"){
        query.bindValue(":entrepot", 0);
    }

    if(query.exec()){
        this->close();
    }else{
        qDebug() << "Error : " << query.lastError();
    }

}

