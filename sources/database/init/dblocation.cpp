#include "headers/database/init/dblocation.h"

LocationInit::LocationInit(){}

void LocationInit::initLocation(){
    tableLocation();
    valueLocation();
}

void LocationInit::tableLocation(){
    QSqlQuery query;
    query.exec("CREATE TABLE EMPLACEMENT (NomEmplacement TEXT PRIMARY KEY, Entrepot INTEGER DEFAULT 0 CHECK (Entrepot IN (0,1)));");
}

void LocationInit::valueLocation(){
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO EMPLACEMENT VALUES ('STOCK',1),('SALLE 01',0);");
    query.exec();
}
