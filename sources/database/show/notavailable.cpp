#include "headers/database/show/notavailable.h"

NotAvailableShow::NotAvailableShow(){}

void NotAvailableShow::showNotAvailable(QTableWidget* notavailableTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT MATERIEL.IdMateriel AS Id, MATERIEL.NomMateriel AS Nom, MATERIEL.Marque AS Marque, MATERIEL.NomEtat AS Etat, CATEGORIE.NomCategorie AS Categorie FROM MATERIEL INNER JOIN CATEGORIE ON CATEGORIE.IdCategorie = MATERIEL.IdCategorie WHERE MATERIEL.Emprunter = 1;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    notavailableTable->setColumnCount(tableColumnCount);
    notavailableTable->setAlternatingRowColors(true);

    setStyleNotAvailable(notavailableTable, tableColumnCount, tableRowCount, model);
}

void NotAvailableShow::setStyleNotAvailable(QTableWidget* notavailableTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    notavailableTable->setRowCount(tableRowCount);
    notavailableTable->setColumnCount(tableColumnCount);
    notavailableTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    notavailableTable->horizontalHeader()->setFont(tableFont);
    notavailableTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    notavailableTable->verticalHeader()->setVisible(false);
    notavailableTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    notavailableTable->setMouseTracking(true);
    notavailableTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    notavailableTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    for (int row = 0; row < notavailableTable->rowCount(); ++row) {
        notavailableTable->setRowHeight(row, 60);
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        notavailableTable->setHorizontalHeaderItem(column, headerItem);

        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            notavailableTable->setItem(row, column, item);

            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}
