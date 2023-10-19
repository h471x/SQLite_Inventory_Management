#ifndef INSCATEGORY_H
#define INSCATEGORY_H

#include <QDialog>
#include "headers/database/init/dbcategory.h"
#include <QKeyEvent>
#include <QString>
#include <QLineEdit>

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

private: //object instances
    Ui::InsertCategory *InsertCategoryUi;
    QSqlQuery query;

private:
    void keyConfig();
    void error();
    void keyPressEvent(QKeyEvent *event) override;

private: //variables
    bool inserted = false;

};

#endif // INSCATEGORY_H
