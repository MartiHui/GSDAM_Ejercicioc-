#include <string>
#include <utility>

#include "datastruct.h"

void DataStruct::setNumCampos(int num) {
    numCampos = num;
}

int DataStruct::getNumCampos() {
    return numCampos;
}

void DataStruct::addCampo(std::string nombre, int len) {
    campos.emplace_back(nombre, len);
}

std::pair<std::string, int> DataStruct::getCampo(int indice) {
    return campos[indice];
}
