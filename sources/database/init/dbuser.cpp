#include "headers/database/init/dbuser.h"

UserInit::UserInit(){}

void UserInit::initUser(){
    tableUser();
    valueUser();
}

void UserInit::tableUser(){
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS UTILISATEUR (UsernameUtilisateur TEXT NOT NULL UNIQUE, NomUtilisateur TEXT NOT NULL , PrenomUtilisateur TEXT , AdresseUtilisateur TEXT  NOT NULL , TelephoneUtilisateur TEXT NOT NULL,PRIMARY KEY(UsernameUtilisateur));");

}

void UserInit::valueUser(){
    QSqlQuery query;
    query.prepare("INSERT OR IGNORE INTO UTILISATEUR(NomUtilisateur,PrenomUtilisateur,AdresseUtilisateur,TelephoneUtilisateur) VALUES(:idusr, :nusr, :pusr, :adr, :phn)");
    query.bindValue(":nusr", "Hatix");
    query.bindValue(":pusr", "Ntsoa");
    query.bindValue(":adr", "Fianarantsoa");
    query.bindValue(":phn", "0387757069");
    query.exec();
}
