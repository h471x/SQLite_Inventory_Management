#include "headers/database/show/admin.h"

AdminShow::AdminShow(){}

void AdminShow::showAdmin(QTableWidget* adminTable) {
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

void AdminShow::setStyleAdmin(QTableWidget* adminTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model) {
    adminTable->setRowCount(tableRowCount);
    adminTable->setColumnCount(tableColumnCount);
    adminTable->setAlternatingRowColors(true);

    // Some adjustments for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    adminTable->horizontalHeader()->setFont(tableFont);
    adminTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    adminTable->verticalHeader()->setVisible(false);
    adminTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    adminTable->setMouseTracking(true);
    adminTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    adminTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    if (tableRowCount > 1) {
        // If there is more than one admin, add the "Actions" column and buttons
        addActionsColumn(adminTable, tableRowCount);
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

void AdminShow::addActionsColumn(QTableWidget* adminTable, int tableRowCount) {
    int actionsColumn = adminTable->columnCount();

    adminTable->setColumnCount(actionsColumn + 1);
    adminTable->setHorizontalHeaderItem(actionsColumn, new QTableWidgetItem("Actions"));

    for (int row = 0; row < tableRowCount; ++row) {
        QPushButton *deleteAdminBtn = new QPushButton(adminTable);
        deleteAdminBtn->setObjectName("actionButton");
        deleteAdminBtn->setIcon(QIcon(":/icons/icons/black/delete.png"));
        deleteAdminBtn->setIconSize(QSize(30, 30));
        deleteAdminBtn->setFocusPolicy(Qt::NoFocus);
        adminTable->setCellWidget(row, actionsColumn, deleteAdminBtn);

        QFont actionFont;
        deleteAdminBtn->setCursor(QCursor(Qt::PointingHandCursor));
        actionFont.setPointSize(9);
        deleteAdminBtn->setFont(actionFont);

        adminTable->setRowHeight(row, 60);

        deleteAdmin(adminTable, deleteAdminBtn);

        if (row % 2 == 0) {
            deleteAdminBtn->setStyleSheet("background-color: #c5cad6;");
        } else {
            deleteAdminBtn->setStyleSheet("background-color: #a2a6ae;");
        }
    }
}


QString AdminShow::selectAdmin(QTableWidget* adminTable) {
    // Get the currently selected item
    QTableWidgetItem* selectedItem = adminTable->currentItem();

    if (selectedItem) {
        // Get the row index of the selected item
        int selectedRow = adminTable->row(selectedItem);

        // Get the data of the row where the cell is
        QString rowData = adminTable->item(selectedRow, 0)->text();
        return rowData;
    } else {
        return "";
    }
}

void AdminShow::deleteAdmin(QTableWidget* adminTable, QPushButton* deleteAdminBtn){
    connect(deleteAdminBtn, &QPushButton::clicked, this, [this, adminTable]() {
        QString id = selectAdmin(adminTable);

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
                query.prepare("DELETE FROM ADMIN WHERE UsernameAdmin = :usrad;");
                query.bindValue(":usrad", id);
                query.exec();
                adminTable->clear();
                adminTable->setRowCount(0);
                adminTable->setColumnCount(0);
                showAdmin(adminTable);
            } else {
                // User clicked "No", do nothing
            }
        }
    });
}
