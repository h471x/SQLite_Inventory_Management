#ifndef INSERTLOCATION_H
#define INSERTLOCATION_H

#include <QDialog>

#include "headers/database/init/dblocation.h"
#include <QKeyEvent>
#include <QString>
#include <QLineEdit>

namespace Ui {
class InsertLocation;
}

class InsertLocation : public QDialog
{
    Q_OBJECT

public:
    explicit InsertLocation(QWidget *parent = nullptr);
    ~InsertLocation();

private slots:
    void on_insertLocation_clicked();

private:
    Ui::InsertLocation *InsertLocationUi;
    QSqlQuery query;
};

#endif // INSERTLOCATION_H
