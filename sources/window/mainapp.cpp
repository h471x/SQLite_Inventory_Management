#include "headers/window/mainapp.h"
#include "headers/window/inscategory.h"

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
void MainApp::on_OptionsBtn_clicked(){ focusOptions(); }
void MainApp::on_HelpBtn_clicked(){ focusHelp(); }

void MainApp::focusHome(){MainUi->Content->setCurrentIndex(0);}
void MainApp::focusMenu(){MainUi->Content->setCurrentIndex(1);}
void MainApp::focusAdmin(){MainUi->Content->setCurrentIndex(2);};
void MainApp::focusFind(){MainUi->Content->setCurrentIndex(3);};
void MainApp::focusFlows(){MainUi->Content->setCurrentIndex(4);};
void MainApp::focusOptions(){MainUi->Content->setCurrentIndex(5);};
void MainApp::focusHelp(){MainUi->Content->setCurrentIndex(6);};

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
//        product.showProduct(tableWidget);
        product.showProduct(MainUi->findWidget);
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


void MainApp::on_NotifBtn_clicked()
{
    QTableWidget* tableWidget = MainUi->homeWidget;
    QSqlQuery query;
    query.prepare("DELETE FROM MATERIEL;");
    query.exec();

    tableWidget->clear(); // Supprime le contenu des cellules
    tableWidget->setRowCount(0); // Supprime les lignes
    tableWidget->setColumnCount(0); // Supprime les colonnes
    home();
}


void MainApp::on_pushButton_clicked()
{
    InsertCategory *categoryInsert = new InsertCategory(); // create the Main App Instance
    categoryInsert->setModal(true);
    categoryInsert->show();
}

