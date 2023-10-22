#include "headers/database/init/triggerreturn.h"

TriggerReturnInit::TriggerReturnInit(){}

void TriggerReturnInit::initTriggerReturn(){
    TriggerReturnCreate();
}

void TriggerReturnInit::TriggerReturnCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS RequeteRemise AFTER UPDATE ON MATERIEL WHEN NEW.Emprunter = 0 BEGIN INSERT INTO REQUETE ('TypeRequete', 'DHRequete', 'UsernameAdmin', 'UsernameUtilisateur', 'NomMateriel', 'NomEtat', 'NomEmplacement') VALUES ('Remise', strftime('%d/%m/%Y %H:%M', 'now', 'localtime'), NEW.UsernameAdmin, NEW.UsernameUtilisateur, NEW.NomMateriel, NEW.NomEtat, NEW.NomEmplacement); END;");
}

