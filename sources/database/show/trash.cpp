#include "headers/database/show/trash.h"

TrashShow::TrashShow(){}

void TrashShow::showTrash(QTableWidget* trashTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT MATERIEL.IdMateriel AS Id, MATERIEL.NomMateriel AS Nom, MATERIEL.Marque AS Marque, MATERIEL.NomEtat AS Etat, CATEGORIE.NomCategorie AS Categorie FROM MATERIEL INNER JOIN CATEGORIE ON CATEGORIE.IdCategorie = MATERIEL.IdCategorie WHERE MATERIEL.Emprunter = 0 AND MATERIEL.NomEtat = 'A Jeter';";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    trashTable->setColumnCount(tableColumnCount);
    trashTable->setAlternatingRowColors(true);

    setStyleTrash(trashTable, tableColumnCount, tableRowCount, model);
}

void TrashShow::setStyleTrash(QTableWidget* trashTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
     trashTable->setRowCount(tableRowCount);
     trashTable->setColumnCount(tableColumnCount);
     trashTable->setAlternatingRowColors(true);

     // Some adjustements for the QTableView
     QFont tableFont;
     tableFont.setPointSize(11);
     trashTable->horizontalHeader()->setFont(tableFont);
     trashTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     trashTable->verticalHeader()->setVisible(false);
     trashTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     trashTable->setMouseTracking(true);
     trashTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
     trashTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

     // Add The Actions columns within the table widget
     trashTable->setColumnCount(tableColumnCount + 1);
     trashTable->setHorizontalHeaderItem(tableColumnCount, new QTableWidgetItem("Actions"));
     trashTable->setAlternatingRowColors(true);

     // Parcourt toutes les lignes de la table
     for (int row = 0; row < trashTable->rowCount(); ++row) {
         PermanentDeleteBtn = new QPushButton(" Delete");
         restoreBtn = new QPushButton(" Restore");

         trashTable->setRowHeight(row, 60);

         deleteRowFeature(trashTable);
         restoreRow(trashTable);

         btnConfig();

         QFont actionFont;
         actionFont.setPointSize(9);
         PermanentDeleteBtn->setFont(actionFont);

        // Widget for the buttons
        QWidget* actionsWidget = new QWidget();
        QHBoxLayout* actionsLayout = new QHBoxLayout(actionsWidget);
        actionsLayout->addWidget(PermanentDeleteBtn);
        actionsLayout->addWidget(restoreBtn);
        actionsLayout->setContentsMargins(0, 0, 0, 0);
        actionsWidget->setLayout(actionsLayout);
        actionsWidget->setCursor(Qt::PointingHandCursor);

        // Ajoute le widget de layout des boutons à chaque cellule de la colonne d'actions
        trashTable->setCellWidget(row, tableColumnCount, actionsWidget);

        // Enable selection for the "Actions" column
        QTableWidgetSelectionRange range(row, tableColumnCount, row, tableColumnCount);
        trashTable->setRangeSelected(range, true);

        // alternate colors for the actions column
        if (row % 2 == 0) {trashTable->cellWidget(row, tableColumnCount)->setStyleSheet("background-color: #c5cad6;");}
        else {trashTable->cellWidget(row, tableColumnCount)->setStyleSheet("background-color: #a2a6ae;");}
     }

     for (int column = 0; column < tableColumnCount; ++column) {
         QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
         trashTable->setHorizontalHeaderItem(column, headerItem);

         for (int row = 0; row < tableRowCount; ++row) {
             QModelIndex index = model->index(row, column);
             QString data = model->data(index).toString();
             QTableWidgetItem* item = new QTableWidgetItem(data);
             trashTable->setItem(row, column, item);

             if (item) {
                 item->setTextAlignment(Qt::AlignCenter);
                 item->setFont(tableFont);
             }
         }
     }
}

QString TrashShow::SelectDiscard(QTableWidget* trashTable) {
    // Get the currently selected item
    QTableWidgetItem* selectedItem = trashTable->currentItem();

    if (selectedItem) {
        // Get the row index of the selected item
        int selectedRow = trashTable->row(selectedItem);

        // Get the data of the row where the cell is
        QString rowData = trashTable->item(selectedRow, 0)->text();
        return rowData;
    } else {
        return "";
    }
}

void TrashShow::btnConfig(){
    PermanentDeleteBtn->setToolTip("Delete");
    PermanentDeleteBtn->setStyleSheet("QToolTip{background-color: #eaeff5;}");
    PermanentDeleteBtn->setIcon(QIcon(":/icons/icons/black/delete.png"));
    PermanentDeleteBtn->setIconSize(QSize(30, 30));
    PermanentDeleteBtn->setFocusPolicy(Qt::NoFocus);

    restoreBtn->setToolTip("Restore");
    restoreBtn->setStyleSheet("QToolTip{background-color: #eaeff5;}");
    restoreBtn->setIcon(QIcon(":/icons/icons/black/reload.png"));
    restoreBtn->setIconSize(QSize(30, 30));
    restoreBtn->setFocusPolicy(Qt::NoFocus);
}

void TrashShow::deleteRowFeature(QTableWidget* trashTable){
    connect(PermanentDeleteBtn, &QPushButton::clicked, this, [this, trashTable]() {
        QString id = SelectDiscard(trashTable);

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
                query.prepare("DELETE FROM MATERIEL WHERE IdMateriel = :idmat;");
                query.bindValue(":idmat", id);
                query.exec();
                trashTable->clear();
                trashTable->setRowCount(0);
                trashTable->setColumnCount(0);
                showTrash(trashTable);
            } else {
                // User clicked "No", do nothing
            }
        }
    });
}

void TrashShow::restoreRow(QTableWidget* trashTable){
    connect(restoreBtn, &QPushButton::clicked, this, [this, trashTable]() {
        QString id2 = SelectDiscard(trashTable);

        if (!id2.isEmpty()) {
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
                query.prepare("UPDATE MATERIEL SET NomEtat = 'Utilisable' WHERE IdMateriel = :idmat;");
                query.bindValue(":idmat", id2);
                query.exec();
                trashTable->clear();
                trashTable->setRowCount(0);
                trashTable->setColumnCount(0);
                showTrash(trashTable);
            } else {
                // User clicked "No", do nothing
            }
        }
    });
}
