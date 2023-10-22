#include "headers/database/init/triggersave.h"

TriggerSaveInit::TriggerSaveInit(){}

void TriggerSaveInit::initTriggerSave(){
    TriggerSaveCreate();
}

void TriggerSaveInit::TriggerSaveCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS RequeteEnregistrer AFTER INSERT ON MATERIEL BEGIN INSERT INTO REQUETE ('TypeRequete', 'DHRequete', 'UsernameAdmin', 'UsernameUtilisateur', 'NomMateriel', 'NomEtat', 'NomEmplacement') VALUES ('Enregistrement', strftime('%d/%m/%Y %H:%M', 'now', 'localtime'), NEW.UsernameAdmin, NEW.UsernameAdmin, NEW.NomMateriel, NEW.NomEtat, NEW.NomEmplacement); END;");
}

