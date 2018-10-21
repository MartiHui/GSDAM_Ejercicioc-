#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
#include <string>

#include "database.h"
#include "datatemplate.h"
#include "data.h"

// La parte gráfica del programa
class Interface {
private:
    int getOption(std::string msg, int minLimit, int maxLimit);
    int getOption(std::string msg);
    bool isNewName(std::vector<Database> databases, std::string name);

public:
    int selectDatabase(std::vector<Database> databases);
    std::string getDatabaseName(std::vector<Database> &databases);
    DataTemplate getDatabaseTemplate(); // Crea una plantilla para una base de datos nueva
    int databaseMenu(std::string databaseName);
    void printDatabaseEntries(std::vector<Data> entries, DataTemplate dataTemplate);
    Data getNewDataEntry(Database* database);
    void searchInEntries(Database* database);
};
#endif // INTERFACE_H
