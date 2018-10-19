#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "database.h"
#include "interface.h"

class Controller {
private:
    char* filename {"databases.log"};

public:
    Interface* interface;
    std::vector<Database> databases;
    Database* currentDatabase = nullptr;

    Controller();
    ~Controller();
    void getDatabases();
    void saveDatabase(Database& db);
    void createDatabase();
    void menuDatabase();
};
#endif // CONTROLLER_H
