#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include <string>

#include "database.h"

class Controller {
private:
    char* filename {"databases.log"};

public:
    std::vector<Database> databases;

    void getDatabases();
};
#endif // CONTROLLER_H
