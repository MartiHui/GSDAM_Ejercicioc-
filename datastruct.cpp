#include <string>
#include <utility>

#include "datastruct.h"

void DataStruct::setNumCampos(int num) {
    numCampos_ = num;
}

int DataStruct::getNumCampos() {
    return numCampos_;
}

void DataStruct::addCampo(std::string nombre, int len) {
    campos_.emplace_back(nombre, len);
}

std::pair<std::string, int> DataStruct::getCampo(int indice) {
    return campos_[indice];
}
