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

    // Add The Actions columns within the table widget
    providerTable->setColumnCount(tableColumnCount + 1);
    providerTable->setHorizontalHeaderItem(tableColumnCount, new QTableWidgetItem("Actions"));
    providerTable->setAlternatingRowColors(true);

    for (int row = 0; row < providerTable->rowCount(); ++row) {
        int actionsColumn = tableColumnCount;

        QPushButton *deleteProviderBtn = new QPushButton(providerTable);
        deleteProviderBtn->setObjectName("actionButton");
        deleteProviderBtn->setIcon(QIcon(":/icons/icons/black/delete.png"));
        deleteProviderBtn->setIconSize(QSize(30, 30));
        deleteProviderBtn->setFocusPolicy(Qt::NoFocus);
        providerTable->setCellWidget(row, actionsColumn, deleteProviderBtn);

        QFont actionFont;
        deleteProviderBtn->setCursor(QCursor(Qt::PointingHandCursor));
        actionFont.setPointSize(9);
        deleteProviderBtn->setFont(actionFont);

        providerTable->setRowHeight(row, 60);

        deleteProvider(providerTable, deleteProviderBtn);

        if (row % 2 == 0) {deleteProviderBtn->setStyleSheet("background-color: #c5cad6;");}
        else {deleteProviderBtn->setStyleSheet("background-color: #a2a6ae;");}
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

QString ProviderShow::selectProvider(QTableWidget* providerTable) {
    // Get the currently selected item
    QTableWidgetItem* selectedItem = providerTable->currentItem();

    if (selectedItem) {
        // Get the row index of the selected item
        int selectedRow = providerTable->row(selectedItem);

        // Get the data of the row where the cell is
        QString rowData = providerTable->item(selectedRow, 0)->text();
        return rowData;
    } else {
        return "";
    }
}

void ProviderShow::deleteProvider(QTableWidget* providerTable, QPushButton* deleteProviderBtn){
    connect(deleteProviderBtn, &QPushButton::clicked, this, [this, providerTable]() {
        QString id = selectProvider(providerTable);

        if (!id.isEmpty()) {
            // Display the confirmation dialog
            QMessageBox msgBox;
            msgBox.setText(" Are you sure?");
            msgBox.setWindowTitle(" Confirm Deletion");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setFocusPolicy(Qt::NoFocus);

            msgBox.setFixedSize(300, 300); // Fix the size

            int confirmResult = msgBox.exec();

            if (confirmResult == QMessageBox::Yes) {
                QSqlQuery query;
                query.prepare("DELETE FROM FOURNISSEUR WHERE NomFournisseur = :fournisseur;");
                query.bindValue(":fournisseur", id);
                query.exec();
                providerTable->clear();
                providerTable->setRowCount(0);
                providerTable->setColumnCount(0);
                showProvider(providerTable);
            } else {
                // User clicked "No", do nothing
            }
        }
    });
}
