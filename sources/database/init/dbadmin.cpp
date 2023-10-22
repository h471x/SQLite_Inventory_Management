#include "headers/database/init/dbadmin.h"

AdminInit::AdminInit(){}

void AdminInit::initAdmin(){
   DbInit& dbInit = DbInit::getInstance();
   dbInit.initdb();
   QSqlDatabase db = dbInit.getConnection();
   tableAdmin(db);
   valueAdmin(db);
}

void AdminInit::tableAdmin(QSqlDatabase db){
    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS ADMIN (UsernameAdmin TEXT NOT NULL UNIQUE ,Password TEXT NOT NULL ,NomAdmin TEXT NOT NULL ,PrenomAdmin TEXT NOT NULL ,TelephoneAdmin TEXT NOT NULL ,AdresseAdmin TEXT NOT NULL ,PRIMARY KEY(UsernameAdmin));");
}

void AdminInit::valueAdmin(QSqlDatabase db){
    QSqlQuery query(db);
    query.prepare("INSERT OR IGNORE INTO ADMIN(UsernameAdmin, Password, NomAdmin, PrenomAdmin, TelephoneAdmin, AdresseAdmin) VALUES(:usernameadmin, :passwordadmin, :nameadmin, :prenom, :phone, :adresse)");
    query.bindValue(":usernameadmin", "admin");
    query.bindValue(":passwordadmin", "adminadmin");
    query.bindValue(":nameadmin", "admin");
    query.bindValue(":prenom", "admin");
    query.bindValue(":phone", "033333333");
    query.bindValue(":adresse", "Fianarantsoa");
    query.exec();
}

