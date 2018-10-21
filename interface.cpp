#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>

#include "interface.h"
#include "database.h"
#include "m_utilities.h"

int Interface::getOption(std::string msg, int minLimit, int maxLimit) {
    std::string input = "";
    int option = 0;

    while (true) {
        std::cout << msg << std::endl;
        std::getline(std::cin, input);

        std::stringstream myStream(input);
        if (myStream >> option && option >= minLimit && option <= maxLimit) {
            break;
        }
        std::cout << "No has elegido una opcion valida." << std::endl;
    }

    return option;
}

int Interface::getOption(std::string msg) {
    std::string input = "";
    int option = 0;

    while (true) {
        std::cout << msg << std::endl;
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

std::string Interface::getDatabaseName(std::vector<Database> &databases) {
    std::string name;
    bool newName = false;

    do { // Evitamos dos bases de datos con el mismo nombre para evitar problemas a la hora de crear los archivos
        std::cout << "Introduce el nombre de la nueva base de datos: " << std::endl;
        std::getline(std::cin, name);
        if (isNewName(databases, name)) {
            newName = true;
        } else {
            std::cout << "Ya existe una base de datos con este nombre. Prueba otra vez" << std::endl;
        }
    } while (!newName);

    return name;
}

bool Interface::isNewName(std::vector<Database> databases, std::string name) {
    bool isNew = true;

    // Pasamos ambos string a comparar a minusculas para compararlos correctamente
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    for (unsigned int i = 0; i < databases.size(); i++) {
        std::string dbName = databases[i].getDatabaseName();
        std::transform(dbName.begin(), dbName.end(), dbName.begin(), ::tolower);
        if (name == dbName) {
            isNew = false;
            break;
        }
    }

    return isNew;
}

DataTemplate Interface::getDatabaseTemplate() {
    DataTemplate ds;

    ds.setNumFields(getOption("Introduce el numero de campos:"));

    std::string name;
    int len;
    for (int i = 0; i < ds.getNumFields(); i++) {
        std::cout << "Nombre del " << to_string(i+1) << "º campo:" << std::endl;
        std::getline(std::cin, name);

        len = getOption("Introduce la longitud del campo:");

        ds.addField(name, len);
    }

    return ds;
}

int Interface::databaseMenu(std::string databaseName) {
    std::cout << "~~~~~~~~~~~~ " << databaseName << " ~~~~~~~~~~~~" << std::endl
            << "1 - Ver entradas" << std::endl
            << "2 - Añadir entrada" << std::endl
            << "3 - Buscar entrada" << std::endl << std::endl
            << "0 - Salir" << std::endl;

     int option = 0;
     option = getOption("Elige una opcion:", 0, 3);

     return option;
}

void Interface::printDatabaseEntries(std::vector<Data> entries, DataTemplate dataTemplate) {
    int numEntries = entries.size();

    std::cout << "Numero de entradas: " << to_string(numEntries) << std::endl;
    for (int x = 0; x < numEntries; x++) {
        std::cout << to_string(x+1) << ".";
        for (int y = 0; y < dataTemplate.getNumFields(); y++) {
            std::cout << "\t" << dataTemplate.getField(y).first
                << ": " << entries[x].getInformation(y) << std::endl;
        }
    }

    std::cout << std::endl << "Presiona cualquier tecla para salir..." << std::endl;
    std::getchar();
}

Data Interface::getNewDataEntry(Database* database) {
    Data data;
    DataTemplate ds = database->getTemplate();
    data.setTemplate(ds);
    std::string line;

    std::cout << "Creando una nueva entrada en la base de datos" << std::endl;
    for (int i = 0; i < ds.getNumFields(); i++) {
        std::cout << ds.getField(i).first << ": (Maximo " << ds.getField(i).second
            << " caracteres.)" << std::endl;

        std::getline(std::cin, line);
        // Nos aseguramos de que la información tenga el número de caracteres correcto.
        line.resize(ds.getField(i).second, '\0');

        data.addInformation(line);
    }

    std::cout << "Nueva entrada creada." << std::endl
        << "Presiona cualquier tecla para salir..." << std::endl;
    std::getchar();

    return data;
}

void Interface::searchInEntries(Database* database) {
    std::cout << "Buscar entrada: " << std::endl
        << "Elige que campo usar para la busqueda: " << std::endl;

    DataTemplate ds = database->getTemplate();
    int fieldIdx = 0;

    for (int i = 0; i < ds.getNumFields(); i++) {
        std::cout << to_string(i+1) << " - " << ds.getField(i).first << std::endl;
    }
    fieldIdx = getOption("", 1, ds.getNumFields()) - 1;

    std::string word;
    std::cout << "Introduce el termino a buscar: " << std::endl;
    std::getline(std::cin, word);

    printDatabaseEntries(database->searchEntries(fieldIdx, word), ds);
}

