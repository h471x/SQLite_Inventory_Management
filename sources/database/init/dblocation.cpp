#include "headers/database/init/dblocation.h"

LocationInit::LocationInit(){}

void LocationInit::initLocation(){
    tableLocation();
    valueLocation();
}

void LocationInit::tableLocation(){
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS EMPLACEMENT (NomEmplacement TEXT PRIMARY KEY, Entrepot INTEGER DEFAULT 0 CHECK(Entrepot IN (0,1)));");
    qDebug() << "Emplcement : " << query.lastError();
}

void LocationInit::valueLocation(){
    QSqlQuery query;
    query.exec("INSERT INTO EMPLACEMENT VALUES ('STOCK'), ('SALLE 01');");
}
