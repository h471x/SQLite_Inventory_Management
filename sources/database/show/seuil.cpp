#include "headers/database/show/seuil.h"

SeuilShow::SeuilShow(){}

void SeuilShow::showSeuil(QTableWidget* seuilTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT IdCategorie AS Id,NomCategorie AS Nom,NbeMateriel AS Qte FROM CATEGORIE WHERE NbeMateriel <= SeuilCategorie;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    seuilTable->setColumnCount(tableColumnCount);
    seuilTable->setAlternatingRowColors(true);

    setStyleSeuil(seuilTable, tableColumnCount, tableRowCount, model);
}

void SeuilShow::setStyleSeuil(QTableWidget* seuilTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    seuilTable->setRowCount(tableRowCount);
    seuilTable->setColumnCount(tableColumnCount);
    seuilTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    seuilTable->horizontalHeader()->setFont(tableFont);
    seuilTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    seuilTable->verticalHeader()->setVisible(false);
    seuilTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    seuilTable->setMouseTracking(true);
    seuilTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    seuilTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    for (int row = 0; row < seuilTable->rowCount(); ++row) {
        seuilTable->setRowHeight(row, 60);
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        seuilTable->setHorizontalHeaderItem(column, headerItem);
        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            seuilTable->setItem(row, column, item);
            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}
