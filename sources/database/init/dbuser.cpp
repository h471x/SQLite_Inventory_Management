#include "headers/database/init/dbuser.h"

UserInit::UserInit(){}

void UserInit::initUser(){
    tableUser();
    valueUser();
}

void UserInit::tableUser(){
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS UTILISATEUR (IdUtilisateur  INTEGER NOT NULL ,NomUtilisateur TEXT NOT NULL ,PrenomUtilisateur TEXT ,AdresseUtilisateur TEXT  NOT NULL ,TelephoneUtilisateur TEXT NOT NULL,PRIMARY KEY(IdUtilisateur));");

}

void UserInit::valueUser(){
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO UTILISATEUR(IdUtilisateur,NomUtilisateur,PrenomUtilisateur,AdresseUtilisateur,TelephoneUtilisateur) VALUES(:idusr, :nusr, :pusr, :adr, :phn)");
    query.bindValue(":idusr", 8);
    query.bindValue(":nusr", "Hatix");
    query.bindValue(":pusr", "Ntsoa");
    query.bindValue(":adr", "Fianarantsoa");
    query.bindValue(":phn", "0387757069");
    query.exec();
}
