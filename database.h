#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <string>

#include "datastruct.h"
#include "data.h"

class Database {
private:
    std::string databaseName;
    DataStruct estructura;
    std::vector<Data> entradas;

public:
    std::string getDatabaseName();
    void setDatabaseName(std::string name);
    DataStruct getEstructura();
    void setEstructura(DataStruct ds);
};
#endif // DATABASE_H
