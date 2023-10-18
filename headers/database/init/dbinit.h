#ifndef DBINIT_H
#define DBINIT_H

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QTableWidget>
#include <QSqlTableModel>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QLabel>
#include <QDialog>

#include <QCoreApplication>
#include <QDate>
#include <QString>

class DbInit
{
public: //Constructor
    DbInit();

public: //Method
    void initdb();
    void closeConnection();

private: //Object Instance
    QSqlDatabase mydb;

public: //Conflict handler
    static DbInit& getInstance();
    QSqlDatabase getConnection();   
};

#endif // DBINIT_H
