#include "headers/database/init/triggerdown.h"
#include <QDebug>

TriggerDownInit::TriggerDownInit(){}

void TriggerDownInit::initTriggerDown(){
    TriggerDownCreate();
}

void TriggerDownInit::TriggerDownCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS trigger_rm_nbe_materiel AFTER DELETE ON MATERIEL WHEN old.IdCategorie =(SELECT IdCategorie FROM CATEGORIE WHERE CATEGORIE.IdCategorie = old.IdCategorie) BEGIN UPDATE CATEGORIE SET NbeMateriel = NbeMateriel -1 WHERE CATEGORIE.IdCategorie = OLD.IdCategorie; END;");
}
