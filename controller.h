#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "database.h"

// Contiene la parte l�gica del programa
class Controller {
private:
    const char* filename_ {"databases.log"};

public:
    std::vector<Database> databases_;
    Database* currentDatabase_ = nullptr;

    Controller();
    ~Controller();
    void getDatabases();
    void saveDatabase(Database& database);
    void createDatabase(std::string databaseName, DataTemplate dataTemplate);
};
#endif // CONTROLLER_H
