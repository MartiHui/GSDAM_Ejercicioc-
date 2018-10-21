#include <iostream>
#include <fstream>

#include "database.h"
#include "datatemplate.h"
#include "data.h"
#include "controller.h"
#include "m_utilities.h"

Controller::Controller() {
    interface_ = new Interface;
    getDatabases();
}

Controller::~Controller() {
    delete interface_;
    if (currentDatabase_) {
        delete currentDatabase_;
    }
}

// Recupero las estructuras de todas las bases de datos guardadas (nombre y plantilla de las entradas)
void Controller::getDatabases() {
    std::ifstream myFile;
    myFile.open(filename_);

    Database db;
    DataTemplate ds;
    while (myFile.peek() != EOF) {
        std::string line;

        // Obtener nombre de la base de datos
        std::getline(myFile, line);
        db.setDatabaseName(line);

        // Obtener n�mero de campos de la estructura
        std::getline(myFile, line);
        ds.setNumFields(std::stoi(line));

        // Obtener el nombre de los campos y su longitud
        for (int i = 0; i < ds.getNumFields(); i++) {
            std::string fieldName;
            std::string fieldLen;

            std::getline(myFile, fieldName);
            std::getline(myFile, fieldLen);
            ds.addField(fieldName, std::stoi(fieldLen));
        }

        db.setTemplate(ds);
        databases_.push_back(db);
    }

    myFile.close();
}

void Controller::saveDatabase(Database& db) {
    std::ofstream myFile;
    myFile.open(filename_, std::ios_base::app);

    myFile << db.getDatabaseName() << std::endl;

    DataTemplate ds = db.getTemplate();
    myFile << ds.getNumFields() << std::endl;
    for (int i = 0; i < ds.getNumFields(); i++) {
        // En una fila guardo el nombre del campo y en la siguiente la longitud
        myFile << ds.getField(i).first << std::endl
            << to_string(ds.getField(i).second) << std::endl;
    }

    myFile.close();
}

void Controller::createDatabase() {
    Database db;

    db.setDatabaseName(interface_->getDatabaseName(databases_));
    db.setTemplate(interface_->getDatabaseTemplate());

    saveDatabase(db);
    databases_.push_back(db);
}

void Controller::manageDatabase() {
    int option = 0;
    bool exit = false;
    currentDatabase_->loadFileEntries();

    do {
        option = interface_->databaseMenu(currentDatabase_->getDatabaseName());
        switch (option) {
            case 0: // Salir al men� de seleccion de base de datos
                exit = true;
                break;

            case 1: // Mostrar todas las entradas de la base de datos
                interface_->printDatabaseEntries(currentDatabase_->getEntries(), currentDatabase_->getTemplate());
                break;

            case 2: // A�adir una entrada a la base de datos
                { // Limitamos el �mbito del objeto Data, de lo contrario no compila
                Data data = interface_->getNewDataEntry(currentDatabase_);
                currentDatabase_->addEntry(data);
                break;
                }

            case 3: // Buscar una palabra entre la informaci�n de las entradas
                interface_->searchInEntries(currentDatabase_);
                break;
        }
    } while (!exit);
}
