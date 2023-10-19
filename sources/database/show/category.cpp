#include "headers/database/show/category.h"

CategoryShow::CategoryShow(){}

void CategoryShow::showCategory(QTableWidget* categoryTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT IdCategorie AS Id,NomCategorie AS Nom,NbeMateriel AS Qte,SeuilCategorie AS Seuil FROM CATEGORIE;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    categoryTable->setColumnCount(tableColumnCount);
    categoryTable->setAlternatingRowColors(true);

    setStyleCategory(categoryTable, tableColumnCount, tableRowCount, model);
}

void CategoryShow::setStyleCategory(QTableWidget* categoryTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    categoryTable->setRowCount(tableRowCount);
    categoryTable->setColumnCount(tableColumnCount);
    categoryTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    categoryTable->horizontalHeader()->setFont(tableFont);
    categoryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    categoryTable->verticalHeader()->setVisible(false);
    categoryTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    categoryTable->setMouseTracking(true);
    categoryTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    categoryTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    for (int row = 0; row < categoryTable->rowCount(); ++row) {
        categoryTable->setRowHeight(row, 60);
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        categoryTable->setHorizontalHeaderItem(column, headerItem);
        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            categoryTable->setItem(row, column, item);
            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}
