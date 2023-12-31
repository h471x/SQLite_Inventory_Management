#ifndef INSPRODUCT_H
#define INSPRODUCT_H

#include "headers/database/init/dbproduct.h"
#include "headers/database/init/dbprovider.h"
#include "headers/database/init/dbetat.h"
#include "headers/database/show/history.h"
#include <QDialog>

namespace Ui {
class InsertProduct;
}

class InsertProduct : public QDialog
{
    Q_OBJECT

public:
    explicit InsertProduct(QWidget *parent = nullptr);
    ~InsertProduct();

private slots:
    void on_pushButton_clicked();
//    void loadCategorieData();
//    void loadFournisseurData();

private:
    Ui::InsertProduct *InsertProductUi;
    QSqlQuery query;
    HistoryShow history;
};

#endif // INSPRODUCT_H
