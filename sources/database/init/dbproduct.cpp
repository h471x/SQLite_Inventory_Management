#include "headers/database/init/dbproduct.h"

ProductInit::ProductInit(){}

void ProductInit::initProduct(){
    tableProduct();
    valueProduct();
}

void ProductInit::tableProduct(){
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS MATERIEL (IdMateriel INTEGER NOT NULL UNIQUE, NomMateriel TEXT NOT NULL , Marque TEXT NOT NULL ,Etat TEXT NOT NULL ,DEnregistrement TEXT NOT NULL , Emprunter INTEGER NOT NULL DEFAULT 0 CHECK (Emprunter IN (0,1)),IdCategorie INTEGER NOT NULL ,NomFournisseur TEXT  ,UsernameAdmin TEXT, UsernameUtilisateur TEXT,PRIMARY KEY(IdMateriel),FOREIGN KEY(IdCategorie)REFERENCES CATEGORIE (IdCategorie) ON UPDATE CASCADE ON DELETE CASCADE FOREIGN KEY(NomFournisseur) REFERENCES FOURNISSEUR (NomFournisseur) ON UPDATE SET NULL ON DELETE SET NULL FOREIGN KEY(UsernameAdmin) REFERENCES ADMIN (UsernameAdmin) ON UPDATE CASCADE ON DELETE SET NULL FOREIGN KEY (UsernameUtilisateur) REFERENCES UTILISATEUR (UsernameUtilisateur) ON UPDATE SET NULL ON DELETE SET NULL);");
}

void ProductInit::valueProduct(){
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO MATERIEL(IdMateriel, NomMateriel, Marque, Etat, DEnregistrement, IdCategorie, NomFournisseur, UsernameAdmin, IdUtilisateur) VALUES(:idmat, :nomat, :marque, :etat, :date, :ic, :pro, :adm, :usr)");
    query.bindValue(":idmat", 1);
    query.bindValue(":nomat", "DELL INSPIRON");    
    query.bindValue(":marque", "DELL");
    query.bindValue(":etat", "3");
    query.bindValue(":date", currentDate);
    query.bindValue(":ic", 1);
    query.bindValue(":pro", "Hatix");
    query.bindValue(":adm", "admin");
    query.bindValue(":usr", 8);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(IdMateriel, NomMateriel, Marque, Etat, DEnregistrement, IdCategorie, NomFournisseur, UsernameAdmin, IdUtilisateur) VALUES(:idmat2, :nomat2, :marque2, :etat2, :date2, :ic2, :pro2, :adm2, :usr2)");
    query.bindValue(":idmat2", 2);
    query.bindValue(":nomat2", "DELL INSPIRON");
    query.bindValue(":marque2", "DELL");
    query.bindValue(":etat2", "3");
    query.bindValue(":date2", currentDate);
    query.bindValue(":ic2", 1);
    query.bindValue(":pro2", "Hatix");
    query.bindValue(":adm2", "admin");
    query.bindValue(":usr2", 8);
    query.exec();

    query.prepare("INSERT OR IGNORE INTO MATERIEL(IdMateriel, NomMateriel, Marque, Etat, DEnregistrement, IdCategorie, NomFournisseur, UsernameAdmin, IdUtilisateur) VALUES(:idmat2, :nomat2, :marque2, :etat2, :date2, :ic2, :pro2, :adm2, :usr2)");
    query.bindValue(":idmat3", 3);
    query.bindValue(":nomat3", "DELL INSPIRON");
    query.bindValue(":marque3", "DELL");
    query.bindValue(":etat3", "3");
    query.bindValue(":date3", currentDate);
    query.bindValue(":ic3", 1);
    query.bindValue(":pro3", "Hatix");
    query.bindValue(":adm3", "admin");
    query.bindValue(":usr3", 8);
    query.exec();


}
