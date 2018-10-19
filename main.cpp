#include <iostream>

#include "interface.h"
#include "controller.h"
#include "m_utilities.h"

int main() {
    Controller* controller = new Controller;
    unsigned int option;
    bool salir = false;

    do {
        option = controller->interface->selectDatabase(controller->databases);
        if (option == 0) {
            salir = true;
        } else if (option == controller->databases.size()+1) {
            controller->createDatabase();
        } else {
            controller->currentDatabase = &controller->databases[option-1];
            controller->menuDatabase();
        }
    } while (!salir);
    std::cout << "ANTES DE BORRAR CONTROLLER" << std::endl;
    delete controller;
    std::cout << "DESPUES DE BORRAR CONTROLLER" << std::endl;
    return 0;
}
