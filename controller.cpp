#include <iostream>
#include <fstream>

#include "database.h"
#include "datastruct.h"
#include "data.h"
#include "controller.h"
#include "m_utilities.h"

void Controller::getDatabases() {
    std::ifstream myFile;
    myFile.open(filename);

    Database db;
    DataStruct ds;
    while (myFile.peek() != EOF) {
        std::string linea;

        // Obtener nombre de la base de datos
        std::getline(myFile, linea);
        db.setDatabaseName(linea);

        // Obtener número de campos de la estructura
        std::getline(myFile, linea);
        ds.setNumCampos(std::stoi(linea));

        // Obtener el nombre de los campos y su longitud
        for (int i = 0; i < ds.getNumCampos(); i++) {
            std::string nombre;
            int longitud;

            std::getline(myFile, nombre);
            std::getline(myFile, linea);
            ds.addCampo(nombre, std::stoi(linea));
        }

        db.setEstructura(ds);
        databases.push_back(db);
    }

    myFile.close();
}
