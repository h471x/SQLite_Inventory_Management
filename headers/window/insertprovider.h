#ifndef INSERTPROVIDER_H
#define INSERTPROVIDER_H

#include <QDialog>

#include "headers/database/init/dbprovider.h"

namespace Ui {
class InsertProvider;
}

class InsertProvider : public QDialog
{
    Q_OBJECT

public:
    explicit InsertProvider(QWidget *parent = nullptr);
    ~InsertProvider();

private slots:
    void on_providerBtn_clicked();

private:
    Ui::InsertProvider *InsertProviderUi;
    QSqlQuery query;

private:
    void error();

};

#endif // INSERTPROVIDER_H
