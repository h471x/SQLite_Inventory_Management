#include "headers/database/init/dbhistory.h"

HistoryInit::HistoryInit(){}

void HistoryInit::initHistory(){
    tableHistory();
}

void HistoryInit::tableHistory(){
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS REQUETE (IdRequete INTEGER NOT NULL PRIMARY KEY,TypeRequete TEXT NOT NULL ,DHRequete TEXT NOT NULL ,UsernameAdmin TEXT NOT NULL,UsernameUtilisateur TEXT NOT NULL,NomMateriel TEXT NOT NULL, NomEtat TEXT NOT NULL, NomEmplacement TEXT NOT NULL);");
}
