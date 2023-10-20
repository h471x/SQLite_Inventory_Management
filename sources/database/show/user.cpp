#include "headers/database/show/user.h"

UserShow::UserShow(){}

void UserShow::showUser(QTableWidget* userTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT UsernameUtilisateur AS Username,NomUtilisateur AS Nom,PrenomUtilisateur AS Prenom ,AdresseUtilisateur AS Adresse ,TelephoneUtilisateur AS Phone FROM UTILISATEUR;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    userTable->setColumnCount(tableColumnCount);
    userTable->setAlternatingRowColors(true);

    setStyleUser(userTable, tableColumnCount, tableRowCount, model);
}

void UserShow::setStyleUser(QTableWidget* userTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    userTable->setRowCount(tableRowCount);
    userTable->setColumnCount(tableColumnCount);
    userTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    userTable->horizontalHeader()->setFont(tableFont);
    userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    userTable->verticalHeader()->setVisible(false);
    userTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    userTable->setMouseTracking(true);
    userTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    userTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    // Add The Actions columns within the table widget
    userTable->setColumnCount(tableColumnCount + 1);
    userTable->setHorizontalHeaderItem(tableColumnCount, new QTableWidgetItem("Actions"));
    userTable->setAlternatingRowColors(true);

    for (int row = 0; row < userTable->rowCount(); ++row) {
        int actionsColumn = tableColumnCount;

        QPushButton *deleteUserBtn = new QPushButton(userTable);
        deleteUserBtn->setObjectName("actionButton");
        deleteUserBtn->setIcon(QIcon(":/icons/icons/black/delete.png"));
        deleteUserBtn->setIconSize(QSize(30, 30));
        deleteUserBtn->setFocusPolicy(Qt::NoFocus);
        userTable->setCellWidget(row, actionsColumn, deleteUserBtn);

        QFont actionFont;
        deleteUserBtn->setCursor(QCursor(Qt::PointingHandCursor));
        actionFont.setPointSize(9);
        deleteUserBtn->setFont(actionFont);

        userTable->setRowHeight(row, 60);

        deleteUser(userTable, deleteUserBtn);

        if (row % 2 == 0) {deleteUserBtn->setStyleSheet("background-color: #c5cad6;");}
        else {deleteUserBtn->setStyleSheet("background-color: #a2a6ae;");}
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        userTable->setHorizontalHeaderItem(column, headerItem);
        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            userTable->setItem(row, column, item);
            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}

QString UserShow::selectUser(QTableWidget* userTable) {
    // Get the currently selected item
    QTableWidgetItem* selectedItem = userTable->currentItem();

    if (selectedItem) {
        // Get the row index of the selected item
        int selectedRow = userTable->row(selectedItem);

        // Get the data of the row where the cell is
        QString rowData = userTable->item(selectedRow, 0)->text();
        return rowData;
    } else {
        return "";
    }
}

void UserShow::deleteUser(QTableWidget* userTable, QPushButton* deleteUserBtn){
    connect(deleteUserBtn, &QPushButton::clicked, this, [this, userTable]() {
        QString id = selectUser(userTable);

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
                query.prepare("DELETE FROM UTILISATEUR WHERE UsernameUtilisateur = :usr;");
                query.bindValue(":usr", id);
                query.exec();
                userTable->clear();
                userTable->setRowCount(0);
                userTable->setColumnCount(0);
                showUser(userTable);
            } else {
                // User clicked "No", do nothing
            }
        }
    });
}
