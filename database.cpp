#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "database.h"
#include "datastruct.h"
#include "data.h"

std::string Database::getDatabaseName() {
    return databaseName_;
}

void Database::setDatabaseName(std::string name) {
    databaseName_ = name;
}

DataStruct Database::getEstructura() {
    return estructura_;
}

void Database::setEstructura(DataStruct ds) {
    estructura_ = ds;
}

std::vector<Data> Database::getEntradas() {
    return entradas_;
}

void Database::loadDatabaseData() {
    std::ifstream myFile;
    myFile.open(databaseName_ + ".txt");

}
