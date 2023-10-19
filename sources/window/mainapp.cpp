#include "headers/window/mainapp.h"

MainApp::MainApp(QWidget *parent)
    : QMainWindow(parent)
    , MainUi(new Ui::MainApp)
{
    MainUi->setupUi(this);
    initMainApp();
    home();
}

void MainApp::initMainApp(){
    MainUi->Content->setCurrentIndex(0); // Display the home page at startup
    MainUi->HomeBtn->setFocus(); //Focus the home button at startup
}

MainApp::~MainApp()
{
    delete MainUi;
}

void MainApp::on_HomeBtn_clicked(){ focusHome(); }
void MainApp::on_MenuBtn_clicked(){ focusMenu(); }
void MainApp::on_AdminBtn_clicked(){ focusAdmin(); }
void MainApp::on_FindBtn_clicked(){ focusFind(); }
void MainApp::on_FlowsBtn_clicked(){ focusFlows(); }
void MainApp::on_AvailableBtn_clicked(){ focusAvailable(); }
void MainApp::on_OptionsBtn_clicked(){ focusOptions(); }
void MainApp::on_HelpBtn_clicked(){ focusHelp(); }

void MainApp::focusHome(){MainUi->Content->setCurrentIndex(0);removeStyleSheet();home();}
void MainApp::focusMenu(){MainUi->Content->setCurrentIndex(1);removeStyleSheet();}
void MainApp::focusAdmin(){MainUi->Content->setCurrentIndex(2);removeStyleSheet();};
void MainApp::focusFind(){MainUi->Content->setCurrentIndex(3);removeStyleSheet();};
void MainApp::focusFlows(){MainUi->Content->setCurrentIndex(4);removeStyleSheet();};
void MainApp::focusAvailable(){MainUi->Content->setCurrentIndex(5);removeStyleSheet();}
void MainApp::focusOptions(){MainUi->Content->setCurrentIndex(6);removeStyleSheet();};
void MainApp::focusHelp(){MainUi->Content->setCurrentIndex(7);removeStyleSheet();};


void MainApp::home(){
    // load home contents
    QTableWidget* tableWidget = MainUi->homeWidget;
    QString query = "SELECT * FROM MATERIEL;";
    QSqlQuery result;
    result.exec(query);

    if (result.next()) {
        tableWidget->horizontalHeader()->setVisible(true);
        QFont tableFont;
        tableFont.setPointSize(11);
        tableWidget->horizontalHeader()->setFont(tableFont);
        tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        tableWidget->setVisible(true);

        product.showProduct(tableWidget);
        history.showHistory(MainUi->findWidget);
        available.showAvailable(MainUi->availableWidget);

    } else {
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->setVisible(false);
    }

}

void MainApp::menu(){
    // load menu contents
}

void MainApp::admin(){
    // load admin contents
};

void MainApp::find(){
    // load find contents
};

void MainApp::flows(){
    // load flows contents
};

void MainApp::options(){
    // load options contents
};

void MainApp::help(){
    // load help contents
};

void MainApp::on_NotifBtn_clicked()
{
      QTableWidget* tableWidget = MainUi->homeWidget;
//    QSqlQuery query;
//    query.prepare("DELETE FROM MATERIEL;");
//    query.exec();

    tableWidget->clear(); // Supprime le contenu des cellules
    tableWidget->setRowCount(0); // Supprime les lignes
    tableWidget->setColumnCount(0); // Supprime les colonnes
    home();
}

void MainApp::removeStyleSheet()
{
    MainUi->HomeBtn->setStyleSheet("");
    MainUi->MenuBtn->setStyleSheet("");
    MainUi->AdminBtn->setStyleSheet("");
    MainUi->FindBtn->setStyleSheet("");
    MainUi->FlowsBtn->setStyleSheet("");
    MainUi->OptionsBtn->setStyleSheet("");
    MainUi->HelpBtn->setStyleSheet("");
}

void MainApp::reloadHistory()
{
    MainUi->findWidget->clear();
    MainUi->findWidget->setRowCount(0); // Supprime les lignes
    MainUi->findWidget->setColumnCount(0); // Supprime les colonnes
    history.showHistory(MainUi->findWidget);
}

void MainApp::on_pushButton_clicked()
{
    InsertCategory *categoryInsert = new InsertCategory();
    categoryInsert->setModal(true);
    categoryInsert->show();
    MainUi->MenuBtn->setStyleSheet("background-color: #c5cad6;border-left: 8px solid #000;font-size: 12.5pt;");
}

void MainApp::on_pushButton_2_clicked()
{
    // Query to retrieve the list of categories
    QSqlQuery categoryQuery("SELECT NomCategorie FROM CATEGORIE");

    if (!categoryQuery.exec()) {
        qDebug() << "Error querying categories: " << categoryQuery.lastError();
        // Display an error message here or handle the error accordingly
    } else {
        // Check if there are no categories
        if (!categoryQuery.next()) {
            qDebug() << "No categories found in the CATEGORIE table";
            // Display an error message here or handle the case of no categories
        } else {
            // At least one category is found; proceed with showing the InsertProduct dialog
            InsertProduct *productInsert = new InsertProduct();
            productInsert->setModal(true);
            productInsert->show();
            connect(productInsert, &QDialog::finished, this, &MainApp::reloadHistory);
            MainUi->MenuBtn->setStyleSheet("background-color: #c5cad6;border-left: 8px solid #000;font-size: 12.5pt;");
        }
    }
}


void MainApp::on_UserBtn_clicked()
{
    InsertUser *userInsert = new InsertUser();
    userInsert->setModal(true);
    userInsert->show();
    MainUi->MenuBtn->setStyleSheet("background-color: #c5cad6;border-left: 8px solid #000;font-size: 12.5pt;");
}

void MainApp::on_SearchBtn_clicked()
{
    MainUi->findWidget->clear();
    MainUi->findWidget->setRowCount(0); // Supprime les lignes
    MainUi->findWidget->setColumnCount(0); // Supprime les colonnes
    history.showHistory(MainUi->findWidget);
}

void MainApp::on_ProviderBtn_clicked()
{
    InsertProvider *providerInsert = new InsertProvider();
    providerInsert->setModal(true);
    providerInsert->show();
    MainUi->MenuBtn->setStyleSheet("background-color: #c5cad6;border-left: 8px solid #000;font-size: 12.5pt;");
}

void MainApp::on_LightBtn_clicked()
{
    QDate currentDate = QDate::currentDate();
    QTableWidget* tableWidget = MainUi->homeWidget;
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 56);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 18);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 5);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 7986514);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 872546);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 123456);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    tableWidget->clear(); // Supprime le contenu des cellules
    tableWidget->setRowCount(0); // Supprime les lignes
    tableWidget->setColumnCount(0); // Supprime les colonnes
    home();
}

void MainApp::on_LightBtn_2_clicked()
{
    QDate currentDate = QDate::currentDate();
    QTableWidget* tableWidget = MainUi->homeWidget;
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES( :nomat2, :marque2, :etat2, :date2, :ic2)");
    // query.bindValue(":idmat2", 5465);
    query.bindValue(":nomat2", "DELL");
    query.bindValue(":marque2", "INSPIRON");
    query.bindValue(":etat2", "3");
    query.bindValue(":date2", currentDate);
    query.bindValue(":ic2", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic);");
    // query.bindValue(":idmat", 6);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 987654);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();
    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 500);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 233);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 777);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(NomMateriel, Marque, Etat, DEnregistrement, IdCategorie) VALUES(:nomat, :marque, :etat, :date, :ic)");
    // query.bindValue(":idmat", 544);
    query.bindValue(":nomat", "DELL");
    query.bindValue(":marque", "INSPIRON");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.exec();

    tableWidget->clear(); // Supprime le contenu des cellules
    tableWidget->setRowCount(0); // Supprime les lignes
    tableWidget->setColumnCount(0); // Supprime les colonnes
    home();

}




