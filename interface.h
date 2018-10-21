#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
#include <string>

#include "database.h"
#include "datastruct.h"
#include "data.h"

class Interface {
private:
    int getOption(std::string mensaje, int minLimit, int maxLimit);
    int getOption(std::string mensaje);

public:
    int selectDatabase(std::vector<Database> databases);
    std::string getDatabaseName();
    DataStruct getDatabaseEstructura();
    int databaseMenu(std::string databaseName);
    void printDatabaseData(std::vector<Data> data, DataStruct dataStruct);
    Data getNewDataEntry(Database* database);
    void searchData(Database* database);
};
#endif // INTERFACE_H
