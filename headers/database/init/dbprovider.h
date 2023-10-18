#ifndef DBPROVIDER_H
#define DBPROVIDER_H

#include "headers/database/init/dbinit.h"

class ProviderInit
{
public: //Constructor
    ProviderInit();

public: //Method
    void initProvider();

public: //Method
    void tableProvider();
    void valueProvider();

};

#endif // DBPROVIDER_H
