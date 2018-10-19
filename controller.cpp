#include <iostream>
#include <fstream>

#include "database.h"
#include "datastruct.h"
#include "data.h"
#include "controller.h"
#include "m_utilities.h"

Controller::Controller() {
    interface = new Interface;
    getDatabases();
}

Controller::~Controller() {
    delete interface;
    if (currentDatabase) {
        std::cout << "ANTES DE BORRAR CURRENTDATABASE" << std::endl;

        delete currentDatabase;
        std::cout << "DESPUES DE BORRAR CURRENTDATABASE" << std::endl;
    }
}

void Controller::getDatabases() {
    std::cout << "Entro en getDatabases" << std::endl;
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
            std::string longitud;

            std::getline(myFile, nombre);
            std::getline(myFile, longitud);
            ds.addCampo(nombre, std::stoi(longitud));
        }

        db.setEstructura(ds);
        databases.push_back(db);
    }

    myFile.close();
}

void Controller::saveDatabase(Database& db) {
    std::ofstream myFile;
    myFile.open(filename, std::ios_base::app);

    myFile << db.getDatabaseName() << std::endl;

    DataStruct ds = db.getEstructura();
    myFile << ds.getNumCampos() << std::endl;
    for (int i = 0; i < ds.getNumCampos(); i++) {
        myFile << ds.getCampo(i).first << std::endl
            << to_string(ds.getCampo(i).second) << std::endl;
    }

    myFile.close();
}

void Controller::createDatabase() {
    Database db;

    db.setDatabaseName(interface->getDatabaseName());
    db.setEstructura(interface->getDatabaseEstructura());

    saveDatabase(db);
    databases.push_back(db);
}

void Controller::menuDatabase() {
    std::cout << currentDatabase->getDatabaseName() << std::endl;

}
