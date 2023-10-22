#include "headers/database/show/history.h"

HistoryShow::HistoryShow(){}

void HistoryShow::showHistory(QTableWidget* historyTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT IdRequete as N°Query,TypeRequete as Type,DHRequete as Time,UsernameAdmin as Admin,UsernameUtilisateur as User,NomMateriel as Product, NomEtat AS Etat, NomEmplacement AS Lieu FROM REQUETE;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = query.count(",") + 1;
    int tableRowCount = model->rowCount();

    historyTable->setColumnCount(tableColumnCount);
    historyTable->setAlternatingRowColors(true);

    setStyleHistory(historyTable, tableColumnCount, tableRowCount, model);
}

void HistoryShow::setStyleHistory(QTableWidget* historyTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    historyTable->setRowCount(tableRowCount);
    historyTable->setColumnCount(tableColumnCount);
    historyTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    historyTable->horizontalHeader()->setFont(tableFont);
    historyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    historyTable->verticalHeader()->setVisible(false);
    historyTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    historyTable->setMouseTracking(true);
    historyTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    historyTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");
    for (int row = 0; row < historyTable->rowCount(); ++row) {
        historyTable->setRowHeight(row, 60);
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        historyTable->setHorizontalHeaderItem(column, headerItem);

        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            historyTable->setItem(row, column, item);

            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }

}

