#include "headers/database/init/triggerup.h"

TriggerUpInit::TriggerUpInit(){}

void TriggerUpInit::initTriggerUp(){
    TriggerUpCreate();
}

void TriggerUpInit::TriggerUpCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS trigger_nbe_materiel AFTER INSERT ON MATERIEL WHEN new.IdCategorie = (SELECT IdCategorie FROM CATEGORIE WHERE CATEGORIE.IdCategorie = new.IdCategorie) BEGIN UPDATE CATEGORIE SET NbeMateriel=NbeMateriel+1 WHERE CATEGORIE.IdCategorie = NEW.IdCategorie; END;");
}
