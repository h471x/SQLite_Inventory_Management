#ifndef PROVIDERSHOW_H
#define PROVIDERSHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/init/dbprovider.h"
#include "headers/database/show/table.h"

class ProviderShow : public QWidget
{
public: //Constructor
    ProviderShow();

public: //Method
    void showProvider(QTableWidget* providerTable);
    void setStyleProvider(QTableWidget* providerTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
    void deleteProvider(QTableWidget* providerTable, QPushButton* deleteProviderBtn);

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    QString selectProvider(QTableWidget* providerTable);

};

#endif // PROVIDERSHOW_H
