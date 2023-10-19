#ifndef AVAILABLESHOW_H
#define AVAILABLESHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/show/table.h"

class AvailableShow : public QWidget
{
public: //Constructor
    AvailableShow();

public: //Method
    void showAvailable(QTableWidget* productTable);
    void setStyleAvailable(QTableWidget* productTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
//    void AvailablebtnConfig();

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    QString handleLend(QTableWidget* productTable);

};

#endif // AVAILABLESHOW_H
