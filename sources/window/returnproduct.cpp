#include "headers/window/returnproduct.h"
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
}

ReturnProduct::~ReturnProduct()
{
    delete ReturnProductUi;
}

void ReturnProduct::on_returnProduct_clicked()
{
    QString id = ReturnProductUi->id->currentText();

    QSqlQuery returnQuery;
    returnQuery.prepare("UPDATE MATERIEL SET Emprunter = 0 WHERE IdMateriel = :id;");
    returnQuery.bindValue(":id", id);
    if (returnQuery.exec()) {
        this->close();
    } else {
        qDebug() << "Insert error : " << returnQuery.lastError();
    }
}

