#ifndef TRASHSHOW_H
#define TRASHSHOW_H

#include "headers/database/init/dbinit.h"
#include "headers/database/show/table.h"

class TrashShow : public QWidget
{
public: //Constructor
    TrashShow();

public: //Method
    void showTrash(QTableWidget* trashTable);
    void setStyleTrash(QTableWidget* trashTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
    void btnConfig();
    void deleteRowFeature(QTableWidget* trashTable);
    void restoreRow(QTableWidget* trashTable);

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QPushButton* PermanentDeleteBtn;
    QPushButton* restoreBtn;
    QFont tableFont;
    QString SelectDiscard(QTableWidget* trashTable);
};

#endif // TRASHSHOW_H
