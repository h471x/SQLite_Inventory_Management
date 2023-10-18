#ifndef PRODUCT_H
#define PRODUCT_H

#include "headers/database/init/dbinit.h"

class ProductShow : public QWidget
{
public: //Constructor
    ProductShow();

public: //Method
    void showProduct(QTableWidget* productTable);
    void setStyle(QTableWidget* productTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model);
    void btnConfig();
    void deleteRowFeature(QTableWidget* productTable);

private: //Object Instance
    QSqlDatabase mydb;

private: //actions buttons
    QPushButton* editBtn;
    QPushButton* deleteBtn;
    QPushButton* infoBtn;
    QFont tableFont;
    QList<int> selectedColumns = {0, 1, 2, 3, 4};
    int tableColumnCount = selectedColumns.size();
    QString handleItemSelectionChanged(QTableWidget* productTable);

};

#endif // PRODUCT_H
