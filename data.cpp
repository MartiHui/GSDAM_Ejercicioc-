#include <string>
#include <vector>

#include "data.h"

DataStruct Data::getEstructura() {
    return estructura_;
}

void Data::setEstructura(DataStruct estructura) {
    estructura_ = estructura;
}

std::string Data::getInformacion(int indice) {
    return informacion_[indice];
}

void Data::addInformacion(std::string info) {
    informacion_.push_back(info);
}
