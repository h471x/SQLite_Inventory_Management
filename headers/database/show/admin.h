#ifndef ADMINSHOW_H
#define ADMINSHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/init/dbadmin.h"
#include "headers/database/show/table.h"

class AdminShow : public QWidget
{
public: //Constructor
    AdminShow();

public: //Method
    void showAdmin(QTableWidget* adminTable);
    void setStyleAdmin(QTableWidget* adminTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
//    void AvailablebtnConfig();

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    // QString handleLend(QTableWidget* productTable);

};

#endif // ADMINSHOW_H
