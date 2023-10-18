#include "headers/window/inscategory.h"
#include "ui_inscategory.h"
#include "headers/window/mainapp.h"

InsertCategory::InsertCategory(QDialog *parent) :
    QDialog(parent),
    InsertCategoryUi(new Ui::InsertCategory)
{
    InsertCategoryUi->setupUi(this);
}

InsertCategory::~InsertCategory()
{
    delete InsertCategoryUi;
}

void InsertCategory::on_InsertCategoryBtn_clicked()
{
    QString category = InsertCategoryUi->CategoryName->text();
//    QString seuil = InsertCategoryUi->Threshold->text();

    if (!category.isNull() && !category.isEmpty()) {
//        int threshold = seuil.toInt();
        // Use placeholders in the query
        query.prepare("INSERT OR IGNORE INTO CATEGORIE(NomCategorie) VALUES(:nom)");
//        query.bindValue(":idcate", threshold);
        query.bindValue(":nom", category);
        query.exec();
        this->close();
        MainApp *app = new MainApp();
        app->focusMenu();
    } else {
        qDebug() << "null : failed";
    }
}

