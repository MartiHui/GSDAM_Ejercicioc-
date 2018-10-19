#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
#include <string>

#include "database.h"
#include "datastruct.h"

class Interface {
private:
    int getOption(std::string mensaje, int minLimit, int maxLimit);
    int getOption(std::string mensaje);

public:
    int selectDatabase(std::vector<Database> databases);
    std::string getDatabaseName();
    DataStruct getDatabaseEstructura();
};
#endif // INTERFACE_H
