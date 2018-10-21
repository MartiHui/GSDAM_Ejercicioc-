#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "database.h"
#include "interface.h"

// Contiene la parte lógica del programa
class Controller {
private:
    const char* filename_ {"databases.log"};

public:
    Interface* interface_;
    std::vector<Database> databases_;
    Database* currentDatabase_ = nullptr;

    Controller();
    ~Controller();
    void getDatabases();
    void saveDatabase(Database& database);
    void createDatabase();
    void manageDatabase();
};
#endif // CONTROLLER_H
