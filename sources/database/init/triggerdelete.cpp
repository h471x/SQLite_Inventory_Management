#include "headers/database/init/triggerdelete.h"

TriggerDeleteInit::TriggerDeleteInit(){}

void TriggerDeleteInit::initTriggerDelete(){
    TriggerDeleteCreate();
}

void TriggerDeleteInit::TriggerDeleteCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS RequeteSupprimer AFTER DELETE ON MATERIEL BEGIN INSERT INTO REQUETE ('TypeRequete','DHRequete','UsernameAdmin','UsernameUtilisateur','NomMateriel') VALUES ('Suppression',datetime('now','localtime'),OLD.UsernameAdmin,OLD.UsernameAdmin,OLD.NomMateriel); END;");
}
