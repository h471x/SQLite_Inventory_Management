#ifndef DBPRODUCT_H
#define DBPRODUCT_H

#include "headers/database/init/dbinit.h"

class ProductInit
{
public: //Constructor
    ProductInit();

public: //Method
    void initProduct();

public: //Method
    void tableProduct();
    void valueProduct();

public: //variables
    QDate currentDate = QDate::currentDate();

};

#endif // DBPRODUCT_H
