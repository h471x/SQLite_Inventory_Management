#include "headers/database/init/triggerlenddown.h"

TriggerLendDownInit::TriggerLendDownInit(){}

void TriggerLendDownInit::initTriggerLendDown(){
    TriggerLendDownCreate();
}

void TriggerLendDownInit::TriggerLendDownCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS DecrementEmprunt AFTER UPDATE ON MATERIEL WHEN NEW.Emprunter = 1 BEGIN UPDATE CATEGORIE SET NbeMateriel = NbeMateriel - 1 WHERE IdCategorie = NEW.IdCategorie; END;");
}
