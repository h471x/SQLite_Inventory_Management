#include "headers/database/init/triggerlend.h"

TriggerLendInit::TriggerLendInit(){}

void TriggerLendInit::initTriggerLend(){
    TriggerLendCreate();
}

void TriggerLendInit::TriggerLendCreate(){
    QSqlQuery query;
    query.exec("CREATE TRIGGER IF NOT EXISTS RequeteEmprunt AFTER UPDATE ON MATERIEL WHEN NEW.Emprunter = 1 BEGIN INSERT INTO REQUETE ('TypeRequete', 'DHRequete', 'UsernameAdmin', 'UsernameUtilisateur', 'NomMateriel', 'NomEtat', 'NomEmplacement') VALUES ('Emprunt', strftime('%d/%m/%Y %H:%M', 'now', 'localtime'), NEW.UsernameAdmin, NEW.UsernameUtilisateur, NEW.NomMateriel, NEW.NomEtat, NEW.NomEmplacement); END;");
}

