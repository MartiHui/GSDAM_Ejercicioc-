#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "interface.h"
#include "database.h"
#include "m_utilities.h"

int Interface::getOption(std::string mensaje, int minLimit, int maxLimit) {
    std::string input = "";
    int option = 0;

    while (true) {
        std::cout << mensaje << std::endl;
        std::getline(std::cin, input);

        std::stringstream myStream(input);
        if (myStream >> option && option >= minLimit && option <= maxLimit) {
            break;
        }
        std::cout << "No has elegido una opcion valida." << std::endl;
    }

    return option;
}

int Interface::getOption(std::string mensaje) {
    std::string input = "";
    int option = 0;

    while (true) {
        std::cout << mensaje << std::endl;
        std::getline(std::cin, input);

        std::stringstream myStream(input);
        if (myStream >> option) {
            break;
        }
        std::cout << "No has elegido una opcion valida." << std::endl;
    }

    return option;
}

int Interface::selectDatabase(std::vector<Database> databases) {
    int dbSize = databases.size();

    std::cout << "Gestor de bases de datos" << std::endl
            << "------------------------" << std::endl;

    int idx;
    for (idx = 0; idx < dbSize; idx++) {
        std::cout << to_string(idx+1) << " - " << databases[idx].getDatabaseName() << std::endl;
    }
    std::cout << to_string(idx+1) << " - " << "Crear nueva base de datos." << std::endl << std::endl;
    std::cout << "0 - Salir." << std::endl;

    std::string mensaje = "Elige una opcion (0-" + to_string(dbSize+1) + "):";
    return getOption(mensaje, 0, dbSize+1);
}

std::string Interface::getDatabaseName() {
    std::string nombre;
    std::cout << "Introduce el nombre de la nueva base de datos: " << std::endl;
    std::getline(std::cin, nombre);
    return nombre;
}

DataStruct Interface::getDatabaseEstructura() {
    DataStruct ds;

    ds.setNumCampos(getOption("Introduce el numero de campos:"));

    std::string nombre;
    int longitud;
    for (int i = 0; i < ds.getNumCampos(); i++) {
        std::cout << "Nombre del " << to_string(i+1) << "º campo:" << std::endl;
        std::getline(std::cin, nombre);

        longitud = getOption("Introduce la longitud del campo:");

        ds.addCampo(nombre, longitud);
    }

    return ds;
}


