#include "headers/database/show/admin.h"

AdminShow::AdminShow(){}

void AdminShow::showAdmin(QTableWidget* adminTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT UsernameAdmin AS UserName, NomAdmin AS Nom, PrenomAdmin AS Prenom, TelephoneAdmin AS Phone, AdresseAdmin AS Adress FROM ADMIN";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    adminTable->setColumnCount(tableColumnCount);
    adminTable->setAlternatingRowColors(true);

    setStyleAdmin(adminTable, tableColumnCount, tableRowCount, model);
}

void AdminShow::setStyleAdmin(QTableWidget* adminTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    adminTable->setRowCount(tableRowCount);
    adminTable->setColumnCount(tableColumnCount);
    adminTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    adminTable->horizontalHeader()->setFont(tableFont);
    adminTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    adminTable->verticalHeader()->setVisible(false);
    adminTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    adminTable->setMouseTracking(true);
    adminTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    adminTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    for (int row = 0; row < adminTable->rowCount(); ++row) {
        adminTable->setRowHeight(row, 60);
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        adminTable->setHorizontalHeaderItem(column, headerItem);
        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            adminTable->setItem(row, column, item);
            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}
