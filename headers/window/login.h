#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QString>
#include <QLineEdit>

#include "headers/window/mainapp.h"
#include "headers/database/init/dbadmin.h"
#include "headers/database/init/dbprovider.h"
#include "headers/database/init/dbcategory.h"
#include "headers/database/init/dbetat.h"
#include "headers/database/init/dblocation.h"
#include "headers/database/init/dbproduct.h"
#include "headers/database/init/dbuser.h"
#include "headers/database/init/dbhistory.h"
#include "headers/database/init/triggerup.h"
#include "headers/database/init/triggerdown.h"
#include "headers/database/init/triggerdelete.h"
#include "headers/database/init/triggersave.h"
#include "headers/database/init/triggerlend.h"
#include "headers/database/init/triggerlenddown.h"
#include "headers/database/init/triggerreturnup.h"
#include "headers/database/init/triggerreturn.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public: //constructor
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_LoginBtn_clicked();

private: //ui
    Ui::Login *LoginUi;

private: //methods
    void dbinit();
    void windowConfig();
    void keyConfig();
    void success();
    void fail();
    void keyPressEvent(QKeyEvent *event) override;

private: //variables
    bool isLoggedIn = false;

private: //db classes Instances
    AdminInit admin;
    CategoryInit category;
    EtatInit etat;
    LocationInit location;
    ProductInit product;
    ProviderInit provider;
    UserInit user;
    HistoryInit history;
    TriggerUpInit triggerup;
    TriggerDownInit triggerdown;
    TriggerDeleteInit triggerdelete;
    TriggerSaveInit triggersave;
    TriggerLendInit triggerlend;
    TriggerLendDownInit triggerlenddown;
    TriggerReturnUpInit triggerreturnup;
    TriggerReturnInit triggerreturn;
    QSqlQuery query;

};

#endif // LOGIN_H
