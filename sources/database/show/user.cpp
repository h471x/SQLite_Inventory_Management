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

    for (int row = 0; row < userTable->rowCount(); ++row) {
        userTable->setRowHeight(row, 60);
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
