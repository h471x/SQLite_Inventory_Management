#ifndef PANNESHOW_H
#define PANNESHOW_H


#include "headers/database/init/dbinit.h"
#include "headers/database/show/table.h"

class PanneShow : public QWidget
{
public: //Constructor
    PanneShow();

public: //Method
    void showPanne(QTableWidget* panneTable);
    void setStylePanne(QTableWidget* panneTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
    void deletePanne(QTableWidget* panneTable, QPushButton* deletePanneBtn);

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QFont tableFont;
    QString selectPanne(QTableWidget* panneTable);

};

#endif // PANNESHOW_H
