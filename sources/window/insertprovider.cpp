#include "headers/window/insertprovider.h"
#include "ui_insertprovider.h"

InsertProvider::InsertProvider(QWidget *parent) :
    QDialog(parent),
    InsertProviderUi(new Ui::InsertProvider)
{
    InsertProviderUi->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

InsertProvider::~InsertProvider()
{
    delete InsertProviderUi;
}

void InsertProvider::on_providerBtn_clicked()
{
    QString provider = InsertProviderUi->provider->text();

    // Check if the provider contains non-whitespace characters
    if (!provider.trimmed().isEmpty()) {
        bool isNumeric;
        provider.toInt(&isNumeric);

        if (!isNumeric) {
            query.prepare("INSERT OR IGNORE INTO FOURNISSEUR(NomFournisseur) VALUES(:fournisseur);");
            query.bindValue(":fournisseur", provider);

            if (query.exec()) {
                if (query.numRowsAffected() > 0) {
                    this->close();
                } else {
                    error(); // Already Existing Provider
                }
            } else {
                error();
            }
        } else {
            error(); // Provider is a number
        }
    } else {
        error(); // Provider is empty or contains only whitespace
    }
}

void InsertProvider::error(){
    InsertProviderUi->provider->clear();
//    setRedBorderCategory(InsertCategoryUi->CategoryName);
//    setRedBorderCategory(InsertCategoryUi->Threshold);
    InsertProviderUi->provider->setFocus();
}

