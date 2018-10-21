#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "database.h"
#include "datastruct.h"
#include "data.h"
#include "m_utilities.h"

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

    while (myFile.peek() != EOF) {
        Data data;
        std::string linea;

        data.setEstructura(estructura_);
        std::getline(myFile, linea);
        decrypt(linea, data);

        entradas_.push_back(data);
    }

    myFile.close();
}

void Database::decrypt(std::string linea, Data& data) {
    int infoBegin = 0;
    int infoLen = 0;
    for (int i = 0; i < data.getEstructura().getNumCampos(); i++) {
        infoBegin += infoLen;
        infoLen = data.getEstructura().getCampo(i).second;
        data.addInformacion(linea.substr(infoBegin, infoLen));
    }
}

void Database::addEntrada(Data data) {
    entradas_.push_back(data);
    std::string info = encrypt(data);
    std::ofstream myFile;
    myFile.open(databaseName_ + ".txt", std::ios::app);
    myFile << info << std::endl;
    myFile.close();
}

std::string Database::encrypt(Data& data) {
    std::string info = "";
    for (int i = 0; i < data.getEstructura().getNumCampos(); i++) {
        std::cout << to_string(i) <<  info << std::endl;
        info += data.getInformacion(i);
    }
    return info;
}

std::vector<Data> Database::buscarEntradas(int campo, std::string busqueda) {
    std::vector<Data> data;
    for (unsigned int i = 0; i < entradas_.size(); i++) {
        if (entradas_[i].getInformacion(campo).find(busqueda) != std::string::npos) {
            data.push_back(entradas_[i]);
        }
    }
    return data;
}
