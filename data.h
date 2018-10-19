#ifndef DATA_H
#define DATA_H
#include <string>
#include <vector>

#include "datastruct.h"

class Data {
private:
    DataStruct estructura_;
    std::vector<std::string> informacion_;

public:
    std::string getInformacion(int indice);
};
#endif // DATA_H
