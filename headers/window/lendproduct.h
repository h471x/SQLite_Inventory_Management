#ifndef LENDPRODUCT_H
#define LENDPRODUCT_H

#include <QDialog>
#include <QString>

#include "headers/database/init/dbuser.h"
#include "headers/database/init/dbproduct.h"

namespace Ui {
class LendProduct;
}

class LendProduct : public QDialog
{
    Q_OBJECT

public:
    explicit LendProduct(const QString& idmateriel, QWidget *parent = nullptr);  // Modify the constructor
    ~LendProduct();

private slots:
    void on_lend_clicked();

private:
    Ui::LendProduct *LendProductUi;
    QString IdMateriel;  // Declare a QString member variable

};

#endif // LENDPRODUCT_H

