#include "headers/database/show/panne.h"

PanneShow::PanneShow(){}

void PanneShow::showPanne(QTableWidget* panneTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT MATERIEL.IdMateriel AS Id,MATERIEL.NomMateriel AS Nom,MATERIEL.Marque AS Marque,ETAT.NomEtat AS Etat,CATEGORIE.NomCategorie AS Categorie,EMPLACEMENT.NomEmplacement AS Lieu FROM MATERIEL INNER JOIN CATEGORIE ON CATEGORIE.IdCategorie = MATERIEL.IdCategorie INNER JOIN ETAT ON ETAT.NomEtat = MATERIEL.NomEtat INNER JOIN EMPLACEMENT ON EMPLACEMENT.NomEmplacement = MATERIEL.NomEmplacement WHERE MATERIEL.NomEtat = 'En panne';";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    panneTable->setColumnCount(tableColumnCount);
    panneTable->setAlternatingRowColors(true);

    setStylePanne(panneTable, tableColumnCount, tableRowCount, model);
}

void PanneShow::setStylePanne(QTableWidget* panneTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
    panneTable->setRowCount(tableRowCount);
    panneTable->setColumnCount(tableColumnCount);
    panneTable->setAlternatingRowColors(true);

    // Some adjustements for the QTableView
    QFont tableFont;
    tableFont.setPointSize(11);
    panneTable->horizontalHeader()->setFont(tableFont);
    panneTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    panneTable->verticalHeader()->setVisible(false);
//    panneTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    panneTable->setMouseTracking(true);
    panneTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    panneTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

    // Add The Actions columns within the table widget
    panneTable->setColumnCount(tableColumnCount + 1);
    panneTable->setHorizontalHeaderItem(tableColumnCount, new QTableWidgetItem("Actions"));
    panneTable->setAlternatingRowColors(true);

    for (int row = 0; row < panneTable->rowCount(); ++row) {
        int actionsColumn = tableColumnCount;

        QPushButton *deletePanneBtn = new QPushButton(panneTable);
        deletePanneBtn->setObjectName("actionButton");
        deletePanneBtn->setIcon(QIcon(":/icons/icons/black/reload.png"));
        deletePanneBtn->setIconSize(QSize(30, 30));
        deletePanneBtn->setFocusPolicy(Qt::NoFocus);
        panneTable->setCellWidget(row, actionsColumn, deletePanneBtn);

        QFont actionFont;
        deletePanneBtn->setCursor(QCursor(Qt::PointingHandCursor));
        actionFont.setPointSize(9);
        deletePanneBtn->setFont(actionFont);

        deletePanne(panneTable, deletePanneBtn);

        if (row % 2 == 0) {deletePanneBtn->setStyleSheet("background-color: #c5cad6;");}
        else {deletePanneBtn->setStyleSheet("background-color: #a2a6ae;");}
        panneTable->setRowHeight(row, 60);
    }

    for (int column = 0; column < tableColumnCount; ++column) {
        QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
        panneTable->setHorizontalHeaderItem(column, headerItem);
        for (int row = 0; row < tableRowCount; ++row) {
            QModelIndex index = model->index(row, column);
            QString data = model->data(index).toString();
            QTableWidgetItem* item = new QTableWidgetItem(data);
            panneTable->setItem(row, column, item);
            if (item) {
                item->setTextAlignment(Qt::AlignCenter);
                item->setFont(tableFont);
            }
        }
    }
}

QString PanneShow::selectPanne(QTableWidget* panneTable) {
    // Get the currently selected item
    QTableWidgetItem* selectedItem = panneTable->currentItem();

    if (selectedItem) {
        // Get the row index of the selected item
        int selectedRow = panneTable->row(selectedItem);

        // Get the data of the row where the cell is
        QString rowData = panneTable->item(selectedRow, 0)->text();
        return rowData;
    } else {
        return "";
    }
}

void PanneShow::deletePanne(QTableWidget* panneTable, QPushButton* deletePanneBtn){
    connect(deletePanneBtn, &QPushButton::clicked, this, [this, panneTable]() {
        QString id = selectPanne(panneTable);

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
                query.prepare("UPDATE MATERIEL SET NomEtat = 'Utilisable' WHERE IdMateriel = :id;");
                query.bindValue(":id", id);
                query.exec();
                panneTable->clear();
                panneTable->setRowCount(0);
                panneTable->setColumnCount(0);
                showPanne(panneTable);
            } else {
                // User clicked "No", do nothing
            }
        }
    });
}
