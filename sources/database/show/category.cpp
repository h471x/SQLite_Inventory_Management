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

    // Add The Actions columns within the table widget
    categoryTable->setColumnCount(tableColumnCount + 1);
    categoryTable->setHorizontalHeaderItem(tableColumnCount, new QTableWidgetItem("Actions"));
    categoryTable->setAlternatingRowColors(true);

    for (int row = 0; row < categoryTable->rowCount(); ++row) {
        int actionsColumn = tableColumnCount;

        QPushButton *deleteBtn = new QPushButton(categoryTable);
        deleteBtn->setObjectName("actionButton");
        deleteBtn->setIcon(QIcon(":/icons/icons/black/delete.png"));
        deleteBtn->setIconSize(QSize(30, 30));
        deleteBtn->setFocusPolicy(Qt::NoFocus);
        categoryTable->setCellWidget(row, actionsColumn, deleteBtn);

        QFont actionFont;
        deleteBtn->setCursor(QCursor(Qt::PointingHandCursor));
        actionFont.setPointSize(9);
        deleteBtn->setFont(actionFont);

        categoryTable->setRowHeight(row, 60);

        deleteCategory(categoryTable, deleteBtn);

        if (row % 2 == 0) {deleteBtn->setStyleSheet("background-color: #c5cad6;");}
        else {deleteBtn->setStyleSheet("background-color: #a2a6ae;");}
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

QString CategoryShow::selectCategory(QTableWidget* categoryTable) {
    // Get the currently selected item
    QTableWidgetItem* selectedItem = categoryTable->currentItem();

    if (selectedItem) {
        // Get the row index of the selected item
        int selectedRow = categoryTable->row(selectedItem);

        // Get the data of the row where the cell is
        QString rowData = categoryTable->item(selectedRow, 0)->text();
        return rowData;
    } else {
        return "";
    }
}

void CategoryShow::deleteCategory(QTableWidget* categoryTable, QPushButton* deleteBtn){
    connect(deleteBtn, &QPushButton::clicked, this, [this, categoryTable]() {
        QString id = selectCategory(categoryTable);

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
                query.prepare("DELETE FROM CATEGORIE WHERE IdCategorie = :idcat;");
                query.bindValue(":idcat", id);
                query.exec();
                categoryTable->clear();
                categoryTable->setRowCount(0);
                categoryTable->setColumnCount(0);
                showCategory(categoryTable);
            } else {
                // User clicked "No", do nothing
            }
        }
    });
}


