#ifndef DBCATEGORY_H
#define DBCATEGORY_H

#include "headers/database/init/dbinit.h"

class CategoryInit
{
public: //Constructor
    CategoryInit();

public: //Method
    void initCategory();

public: //Method
    void tableCategory();
    void valueCategory();

public: //variables
    QDate currentDate = QDate::currentDate();

};

#endif // DBCATEGORY_H
