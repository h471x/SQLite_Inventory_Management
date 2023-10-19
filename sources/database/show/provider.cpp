#include "headers/database/show/provider.h"

ProviderShow::ProviderShow(){}

void ProviderShow::showProvider(QTableWidget* providerTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT NomFournisseur AS Nom FROM FOURNISSEUR;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    providerTable->setColumnCount(tableColumnCount);
    providerTable->setAlternatingRowColors(true);

    setStyleProvider(providerTable, tableColumnCount, tableRowCount, model);
}

void ProviderShow::setStyleProvider(QTableWidget* providerTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    providerTable->setRowCount(tableRowCount);
    providerTable->setColumnCount(tableColumnCount);
    providerTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    providerTable->horizontalHeader()->setFont(tableFont);
    providerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    providerTable->verticalHeader()->setVisible(false);
    providerTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    providerTable->setMouseTracking(true);
    providerTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    providerTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    for (int row = 0; row < providerTable->rowCount(); ++row) {
        providerTable->setRowHeight(row, 60);
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        providerTable->setHorizontalHeaderItem(column, headerItem);
        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            providerTable->setItem(row, column, item);
            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}
