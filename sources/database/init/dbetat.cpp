#include "headers/database/init/dbetat.h"

EtatInit::EtatInit(){}

void EtatInit::initEtat(){
    tableEtat();
    valueEtat();
}

void EtatInit::tableEtat(){
    QSqlQuery query;
    query.exec("CREATE TABLE ETAT (NomEtat TEXT PRIMARY KEY );");
}

void EtatInit::valueEtat(){
    QSqlQuery query;
    query.prepare("INSERT INTO ETAT VALUES ('Utilisable'),('En panne'),('A Jeter');");
    query.exec();
}
