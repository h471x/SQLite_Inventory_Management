#ifndef RETURNPRODUCT_H
#define RETURNPRODUCT_H

#include <QDialog>
#include <QString>

#include "headers/database/init/dbproduct.h"

namespace Ui {
class ReturnProduct;
}

class ReturnProduct : public QDialog
{
    Q_OBJECT

public:
    explicit ReturnProduct(QWidget *parent = nullptr);
    ~ReturnProduct();

private slots:
    void on_returnProduct_clicked();

private:
    Ui::ReturnProduct *ReturnProductUi;
};

#endif // RETURNPRODUCT_H
