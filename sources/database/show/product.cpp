#include "headers/database/show/product.h"

ProductShow::ProductShow(){}

void ProductShow::showProduct(QTableWidget* productTable){
    TableView* model = new TableView(this, mydb);
    QString query = "SELECT MATERIEL.IdMateriel AS Id,MATERIEL.NomMateriel AS Nom,MATERIEL.Marque AS Marque,ETAT.NomEtat AS Etat,CATEGORIE.NomCategorie AS Categorie,MATERIEL.DEnregistrement AS Date,ADMIN.UsernameAdmin AS Admin,FOURNISSEUR.NomFournisseur AS Fournisseur,EMPLACEMENT.NomEmplacement AS Lieu FROM MATERIEL INNER JOIN CATEGORIE ON CATEGORIE.IdCategorie = MATERIEL.IdCategorie INNER JOIN ADMIN ON ADMIN.UsernameAdmin = MATERIEL.UsernameAdmin INNER JOIN FOURNISSEUR ON FOURNISSEUR.NomFournisseur = MATERIEL.NomFournisseur INNER JOIN ETAT ON ETAT.NomEtat = MATERIEL.NomEtat INNER JOIN EMPLACEMENT ON EMPLACEMENT.NomEmplacement = MATERIEL.NomEmplacement;";
    model->setQuery(query);
    model->select();

    int tableColumnCount = model->columnCount();
    int tableRowCount = model->rowCount();

    productTable->setColumnCount(tableColumnCount);
    productTable->setAlternatingRowColors(true);

    setStyle(productTable, tableColumnCount, tableRowCount, model);
}

void ProductShow::setStyle(QTableWidget* productTable, int tableColumnCount, int tableRowCount, QSqlTableModel* model){
     productTable->setRowCount(tableRowCount);
     productTable->setColumnCount(tableColumnCount);
     productTable->setAlternatingRowColors(true);

     // Some adjustements for the QTableView
     QFont tableFont;
     tableFont.setPointSize(11);
     productTable->horizontalHeader()->setFont(tableFont);
     productTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     productTable->verticalHeader()->setVisible(false);
     productTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     productTable->setMouseTracking(true);
     productTable->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
     productTable->setStyleSheet("QTableWidget::item:selected { background-color: #d4d8e2; color: #000; }");

     // Add The Actions columns within the table widget
//     productTable->setColumnCount(tableColumnCount + 1);
//     productTable->setHorizontalHeaderItem(tableColumnCount, new QTableWidgetItem("Actions"));
//     productTable->setAlternatingRowColors(true);

     // Parcourt toutes les lignes de la table
     for (int row = 0; row < productTable->rowCount(); ++row) {

//         editBtn = new QPushButton();
//         deleteBtn = new QPushButton(" Delete");
//         infoBtn = new QPushButton(" Info");

         productTable->setRowHeight(row, 60);

//         deleteRowFeature(productTable);

//         btnConfig();

//         QFont actionFont;
//         editBtn->setCursor(QCursor(Qt::PointingHandCursor));
//         actionFont.setPointSize(9);
////         editBtn->setFont(actionFont);
//         deleteBtn->setFont(actionFont);
////         infoBtn->setFont(actionFont);

//        // Widget for the buttons
//        QWidget* actionsWidget = new QWidget();
//        QHBoxLayout* actionsLayout = new QHBoxLayout(actionsWidget);
////        actionsLayout->addWidget(infoBtn);
////        actionsLayout->addWidget(editBtn);
//        actionsLayout->addWidget(deleteBtn);
//        actionsLayout->setContentsMargins(0, 0, 0, 0);
//        actionsWidget->setLayout(actionsLayout);
//        actionsWidget->setCursor(Qt::PointingHandCursor);

//        // Ajoute le widget de layout des boutons à chaque cellule de la colonne d'actions
//        productTable->setCellWidget(row, tableColumnCount, actionsWidget);

//        // Enable selection for the "Actions" column
//        QTableWidgetSelectionRange range(row, tableColumnCount, row, tableColumnCount);
//        productTable->setRangeSelected(range, true);

//        // alternate colors for the actions column
//        if (row % 2 == 0) {productTable->cellWidget(row, tableColumnCount)->setStyleSheet("background-color: #c5cad6;");}
//        else {productTable->cellWidget(row, tableColumnCount)->setStyleSheet("background-color: #a2a6ae;");}
     }

     for (int column = 0; column < tableColumnCount; ++column) {
         QTableWidgetItem* headerItem = new QTableWidgetItem(model->headerData(column, Qt::Horizontal).toString());
         productTable->setHorizontalHeaderItem(column, headerItem);

         for (int row = 0; row < tableRowCount; ++row) {
             QModelIndex index = model->index(row, column);
             QString data = model->data(index).toString();
             QTableWidgetItem* item = new QTableWidgetItem(data);
             productTable->setItem(row, column, item);

             if (item) {
                 item->setTextAlignment(Qt::AlignCenter);
                 item->setFont(tableFont);
             }
         }
     }
}

//QString ProductShow::handleItemSelectionChanged(QTableWidget* productTable) {
//    // Get the currently selected item
//    QTableWidgetItem* selectedItem = productTable->currentItem();

//    if (selectedItem) {
//        // Get the row index of the selected item
//        int selectedRow = productTable->row(selectedItem);

//        // Get the data of the row where the cell is
//        QString rowData = productTable->item(selectedRow, 0)->text();
//        return rowData;
//    } else {
//        return "";
//    }
//}

//void ProductShow::btnConfig(){
//    //Tool Tips
////    editBtn->setToolTip("Edit");
//    deleteBtn->setToolTip("Delete");
////    infoBtn->setToolTip("Infos");

////    editBtn->setStyleSheet("QToolTip{background-color: #eaeff5;}");
//    deleteBtn->setStyleSheet("QToolTip{background-color: #eaeff5;}");
////    infoBtn->setStyleSheet("QToolTip{background-color: #eaeff5;}");

//    // Change the icons of the Buttons here
////    editBtn->setIcon(QIcon(":/icons/icons/black/edit.svg"));
////    editBtn->setIconSize(QSize(30, 30));

//    deleteBtn->setIcon(QIcon(":/icons/icons/black/delete.png"));
//    deleteBtn->setIconSize(QSize(30, 30));

////    infoBtn->setIcon(QIcon(":/icons/icons/black/info.png"));
////    infoBtn->setIconSize(QSize(30, 30));

//    // Set the focud Policy to No focus
////    editBtn->setFocusPolicy(Qt::NoFocus);
//    deleteBtn->setFocusPolicy(Qt::NoFocus);
////    infoBtn->setFocusPolicy(Qt::NoFocus);
//}

//void ProductShow::deleteRowFeature(QTableWidget* productTable){
//    connect(deleteBtn, &QPushButton::clicked, this, [this, productTable]() {
//        QString id = handleItemSelectionChanged(productTable);

//        if (!id.isEmpty()) {
//            // Display the confirmation dialog
//            QMessageBox msgBox;
//            msgBox.setText(" Are you sure?");
//            msgBox.setWindowTitle(" Confirm Deletion");
//            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//            msgBox.setFocusPolicy(Qt::NoFocus);

//            msgBox.setFixedSize(300, 300); // Fix the size

//            int confirmResult = msgBox.exec();

//            if (confirmResult == QMessageBox::Yes) {
//                QSqlQuery query;
//                query.prepare("DELETE FROM MATERIEL WHERE IdMateriel = :idmat;");
//                query.bindValue(":idmat", id);
//                query.exec();
//                productTable->clear();
//                productTable->setRowCount(0);
//                productTable->setColumnCount(0);
//                showProduct(productTable);
//            } else {
//                // User clicked "No", do nothing
//            }
//        }
//    });
//}

//        connect(deleteBtn, &QPushButton::clicked, this, [this, productTable]() {
//            QString id = handleItemSelectionChanged(productTable);
//            QSqlQuery query;
//            query.prepare("DELETE FROM MATERIEL WHERE IdMateriel = :idmat;");
//            query.bindValue(":idmat", id);
//            query.exec();
//            productTable->clear(); // Supprime le contenu des cellules
//            productTable->setRowCount(0); // Supprime les lignes
//            productTable->setColumnCount(0); // Supprime les colonnes
//            showProduct(productTable);
//        });




