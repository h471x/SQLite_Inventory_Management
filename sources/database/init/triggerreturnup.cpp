#include "headers/database/init/triggerreturnup.h"

TriggerReturnUpInit::TriggerReturnUpInit(){}

void TriggerReturnUpInit::initTriggerReturnUp(){
    TriggerReturnUpCreate();
}

void TriggerReturnUpInit::TriggerReturnUpCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS IncrementRemise AFTER UPDATE ON MATERIEL WHEN NEW.Emprunter = 0 AND NEW.NomEtat = 'Utilisable' BEGIN UPDATE CATEGORIE SET NbeMateriel = NbeMateriel + 1 WHERE IdCategorie = NEW.IdCategorie; END;");
}
