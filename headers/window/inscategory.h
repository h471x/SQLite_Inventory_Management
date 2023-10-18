#ifndef INSCATEGORY_H
#define INSCATEGORY_H

#include <QDialog>

#include "headers/database/init/dbcategory.h"

namespace Ui {
class InsertCategory;
}

class InsertCategory : public QDialog
{
    Q_OBJECT

public:
    explicit InsertCategory(QDialog *parent = nullptr);
    ~InsertCategory();

private slots:
    void on_InsertCategoryBtn_clicked();

private:
    Ui::InsertCategory *InsertCategoryUi;
    QSqlQuery query;
};

#endif // INSCATEGORY_H
