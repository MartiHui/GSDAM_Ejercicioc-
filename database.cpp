#include <string>

#include "database.h"
#include "datastruct.h"

std::string Database::getDatabaseName() {
    return databaseName;
}

void Database::setDatabaseName(std::string name) {
    databaseName = name;
}

DataStruct Database::getEstructura() {
    return estructura;
}

void Database::setEstructura(DataStruct ds) {
    estructura = ds;
}
