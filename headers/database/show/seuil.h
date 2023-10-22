#ifndef SEUILSHOW_H
#define SEUILSHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/init/dbcategory.h"
#include "headers/database/show/table.h"

class SeuilShow : public QWidget
{
public: //Constructor
    SeuilShow();

public: //Method
    void showSeuil(QTableWidget* seuilTable);
    void setStyleSeuil(QTableWidget* seuilTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
//    void AvailablebtnConfig();
//    void deleteCategory(QTableWidget* categoryTable, QPushButton* deleteBtn);

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
//    QString selectCategory(QTableWidget* categoryTable);

};

#endif // SEUILSHOW_H
