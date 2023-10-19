#ifndef CATEGORYSHOW_H
#define CATEGORYSHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/init/dbcategory.h"
#include "headers/database/show/table.h"

class CategoryShow : public QWidget
{
public: //Constructor
    CategoryShow();

public: //Method
    void showCategory(QTableWidget* categoryTable);
    void setStyleCategory(QTableWidget* categoryTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
//    void AvailablebtnConfig();

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    // QString handleLend(QTableWidget* productTable);

};

#endif // CATEGORYSHOW_H
