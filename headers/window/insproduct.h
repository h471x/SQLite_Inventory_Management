#ifndef INSPRODUCT_H
#define INSPRODUCT_H

#include "headers/database/init/dbproduct.h"
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

private:
    Ui::InsertProduct *InsertProductUi;
    QSqlQuery query;
};

#endif // INSPRODUCT_H
