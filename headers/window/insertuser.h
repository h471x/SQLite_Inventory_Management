#ifndef INSERTUSER_H
#define INSERTUSER_H

#include <QDialog>

#include "headers/database/init/dbuser.h"

namespace Ui {
class InsertUser;
}

class InsertUser : public QDialog
{
    Q_OBJECT

public:
    explicit InsertUser(QWidget *parent = nullptr);
    ~InsertUser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InsertUser *InsertUserUi;
    QSqlQuery query;
};

#endif // INSERTUSER_H
