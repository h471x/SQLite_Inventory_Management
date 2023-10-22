#ifndef DBADMIN_H
#define DBADMIN_H

#include "headers/database/init/dbinit.h"

class AdminInit
{
public: //Constructor
    AdminInit();

public: //Method
    void initAdmin();

private: //Method
    void tableAdmin(QSqlDatabase db);
    void valueAdmin(QSqlDatabase db);

};

#endif // DBADMIN_H
