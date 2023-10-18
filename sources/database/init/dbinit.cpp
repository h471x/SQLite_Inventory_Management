#include "headers/database/init/dbinit.h"

DbInit::DbInit(){}

void DbInit::initdb(){
    // Get the directory of the application executable
    QString appDirPath = QCoreApplication::applicationDirPath();

    // Append the relative path to the database file
    QString dbFilePath = appDirPath + "/database.db";

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(dbFilePath);

    if (!mydb.open()) {
        return;
    }else if(mydb.open()){
        QSqlQuery query;
        query.exec("PRAGMA foreign_keys = ON;");
    }
}

DbInit& DbInit::getInstance()
{
    static DbInit instance;
    return instance;
}

QSqlDatabase DbInit::getConnection()
{
    return mydb;
}

void DbInit::closeConnection()
{
    mydb.close();
}
