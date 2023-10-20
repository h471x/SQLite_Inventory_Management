#ifndef INSERTADMIN_H
#define INSERTADMIN_H

#include <QDialog>

#include "headers/database/init/dbadmin.h"
#include <QKeyEvent>
#include <QString>
#include <QLineEdit>

namespace Ui {
class InsertAdmin;
}

class InsertAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit InsertAdmin(QWidget *parent = nullptr);
    ~InsertAdmin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InsertAdmin *InsertAdminUi;
    QSqlQuery query;
};

#endif // INSERTADMIN_H
