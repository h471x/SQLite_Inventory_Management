#ifndef NOTAVAILABLESHOW_H
#define NOTAVAILABLESHOW_H


#include "headers/database/init/dbinit.h"
#include "headers/database/show/table.h"

class NotAvailableShow : public QWidget
{
public: //Constructor
    NotAvailableShow();

public: //Method
    void showNotAvailable(QTableWidget* productTable);
    void setStyleNotAvailable(QTableWidget* productTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
//    void AvailablebtnConfig();

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    QString handleLend(QTableWidget* productTable);

};

#endif // NOTAVAILABLESHOW_H
