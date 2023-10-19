#ifndef USERSHOW_H
#define USERSHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/init/dbuser.h"
#include "headers/database/show/table.h"

class UserShow : public QWidget
{
public: //Constructor
    UserShow();

public: //Method
    void showUser(QTableWidget* userTable);
    void setStyleUser(QTableWidget* userTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
//    void AvailablebtnConfig();

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    // QString handleLend(QTableWidget* productTable);

};

#endif // USERSHOW_H
