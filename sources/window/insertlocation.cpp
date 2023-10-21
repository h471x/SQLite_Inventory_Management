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
    QString emplacement = InsertLocationUi->emplacement->text();
    QString type = InsertLocationUi->type->currentText();

    query.prepare("INSERT INTO EMPLACEMENT VALUES (:emplacement, :type);");
    query.bindValue(":emplacement", emplacement);

    if(type == "Oui"){
        query.bindValue(":type", 1);
    }else if(type == "Non"){
        query.bindValue(":type", 0);
    }

    if(query.exec()){
        this->close();
    }else{
        qDebug() << "Error : " << query.lastError();
    }
}

