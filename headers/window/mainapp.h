#ifndef MAINAPP_H
#define MAINAPP_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

#include "ui_mainapp.h"
#include "headers/database/show/product.h"
#include "headers/database/show/history.h"
#include "headers/database/show/available.h"
#include "headers/database/show/notavailable.h"
#include "headers/database/show/seuil.h"
#include "headers/database/show/panne.h"
#include "headers/window/inscategory.h"
#include "headers/window/insproduct.h"
#include "headers/window/lendproduct.h"
#include "headers/window/returnproduct.h"
#include "headers/window/insertuser.h"
#include "headers/window/insertprovider.h"
#include "headers/window/insertadmin.h"
#include "headers/window/insertlocation.h"
#include "headers/window/pdfsave.h"
#include "headers/database/show/admin.h"
#include "headers/database/show/category.h"
#include "headers/database/show/provider.h"
#include "headers/database/show/user.h"
#include "headers/database/show/trash.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainApp; }
QT_END_NAMESPACE

class MainApp : public QMainWindow
{
    Q_OBJECT

public: //Constructor & Deconstructor
    MainApp(QWidget *parent = nullptr);
    ~MainApp();

private slots:
    void on_HomeBtn_clicked();
    void on_MenuBtn_clicked();
    void on_AdminBtn_clicked();
    void on_FindBtn_clicked();
    void on_OptionsBtn_clicked();
    void on_HelpBtn_clicked();
    void reloadHistory();
    void on_LightBtn_clicked();
    void on_LightBtn_2_clicked();
//    void on_NotifBtn_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_UserBtn_clicked();
//    void on_SearchBtn_clicked();
    void on_ProviderBtn_clicked();
    void on_AvailableBtn_clicked();  
    void on_LendBtn_clicked();
    void on_ReturnBtn_clicked();
    void on_newAdmin_clicked();
    void on_PanneBtn_clicked();
    void on_locationBtn_clicked();
    void on_saveHistoryBtn_clicked();
    void on_deleteHistoryBtn_clicked();
    void on_saveProductBtn_clicked();

    void on_StatsBtn_clicked();

private: //ui
    Ui::MainApp *MainUi;

public: //Methods
    void initMainApp();
    void focusHome();
    void focusMenu();
    void focusAdmin();
    void focusFind();
    void focusFlows();
    void focusAvailable();
    void focusPanne();
    void focusOptions();
    void focusHelp();
    void focusStats();
    void removeStyleSheet();

public: //Methods
    void home();
    void menu();
    void admin();
    void find();
    void flows();
    void options();
    void help();

private: //data from database classes
    ProductShow product;
    TrashShow trash;
    HistoryShow history;
    AvailableShow available;
    NotAvailableShow notavailable;
    PanneShow panne;
    AdminShow adminShow;
    CategoryShow categoryShow;
    SeuilShow seuilShow;
    ProviderShow providerShow;
    UserShow userShow;

private: //table widget
    QString getIdProduct();


};
#endif // MAINAPP_H
