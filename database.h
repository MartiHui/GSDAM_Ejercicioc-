#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <string>

#include "datastruct.h"
#include "data.h"

class Database {
private:
    std::string databaseName_;
    DataStruct estructura_;
    std::vector<Data> entradas_;

public:
    std::string getDatabaseName();
    void setDatabaseName(std::string name);
    DataStruct getEstructura();
    void setEstructura(DataStruct ds);
    std::vector<Data> getEntradas();
    void loadDatabaseData();
};
#endif // DATABASE_H
