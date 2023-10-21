#include "headers/database/init/dbetat.h"

EtatInit::EtatInit(){}

void EtatInit::initEtat(){
    tableEtat();
    valueEtat();
}

void EtatInit::tableEtat(){
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS ETAT (NomEtat TEXT PRIMARY KEY );");
}

void EtatInit::valueEtat(){
    QSqlQuery query;
    query.exec("INSERT OR IGNORE INTO ETAT VALUES ('Utilisable'),('En panne'),('A Jeter');");
}
