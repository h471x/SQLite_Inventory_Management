#ifndef HISTORYSHOW_H
#define HISTORYSHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/show/table.h"

class HistoryShow : public QWidget
{
public: //Constructor
    HistoryShow();

public: //Method
    void showHistory(QTableWidget* productTable);
    void setStyleHistory(QTableWidget* productTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    QString handleItemSelectionChanged(QTableWidget* productTable);

};

#endif // HISTORYSHOW_H
