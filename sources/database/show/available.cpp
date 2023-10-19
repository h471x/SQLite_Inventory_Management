#include "headers/database/show/available.h"

AvailableShow::AvailableShow(){}

void AvailableShow::showAvailable(QTableWidget* availableTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT MATERIEL.IdMateriel AS Id, MATERIEL.NomMateriel AS Nom, MATERIEL.Marque AS Marque, MATERIEL.Etat AS Etat, CATEGORIE.NomCategorie AS Categorie FROM MATERIEL INNER JOIN CATEGORIE ON CATEGORIE.IdCategorie = MATERIEL.IdCategorie WHERE MATERIEL.Emprunter = 0;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    availableTable->setColumnCount(tableColumnCount);
    availableTable->setAlternatingRowColors(true);

    setStyleAvailable(availableTable, tableColumnCount, tableRowCount, model);
}

void AvailableShow::setStyleAvailable(QTableWidget* availableTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    availableTable->setRowCount(tableRowCount);
    availableTable->setColumnCount(tableColumnCount);
    availableTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    availableTable->horizontalHeader()->setFont(tableFont);
    availableTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    availableTable->verticalHeader()->setVisible(false);
    availableTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    availableTable->setMouseTracking(true);
    availableTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    availableTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

      // Add The Actions columns within the table widget
    availableTable->setColumnCount(tableColumnCount + 1);
    availableTable->setHorizontalHeaderItem(tableColumnCount, new QTableWidgetItem("Actions"));
    availableTable->setAlternatingRowColors(true);

    for (int row = 0; row < availableTable->rowCount(); ++row) {
        int actionsColumn = tableColumnCount;

        QPushButton *lendBtn = new QPushButton("  Lend", availableTable);
        lendBtn->setObjectName("actionButton");
        lendBtn->setIcon(QIcon(":/icons/icons/black/add.png"));
        lendBtn->setIconSize(QSize(30, 30));
        lendBtn->setFocusPolicy(Qt::NoFocus);
        availableTable->setCellWidget(row, actionsColumn, lendBtn);

        QFont actionFont;
        lendBtn->setCursor(QCursor(Qt::PointingHandCursor));
        actionFont.setPointSize(9);
        lendBtn->setFont(actionFont);

        availableTable->setRowHeight(row, 60);

        if (row % 2 == 0) {lendBtn->setStyleSheet("background-color: #c5cad6;");}
        else {lendBtn->setStyleSheet("background-color: #a2a6ae;");}
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        availableTable->setHorizontalHeaderItem(column, headerItem);

        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            availableTable->setItem(row, column, item);

            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}


