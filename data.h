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
    DataStruct getEstructura();
    void setEstructura(DataStruct estructura);
    std::string getInformacion(int indice);
    void addInformacion(std::string info);
};
#endif // DATA_H
