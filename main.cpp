#include <iostream>
#include <string>

#include "controller.h"

int main() {
    Controller* controller = new Controller;
    unsigned int option;
    bool salir = false;

    do {
        option = controller->interface_->selectDatabase(controller->databases_);

        if (option == 0) {
            salir = true;
        } else if (option == controller->databases_.size()+1) {
            controller->createDatabase();
        } else {
            controller->currentDatabase_ = &controller->databases_[option-1];
            controller->manageDatabase();
        }
    } while (!salir);

    //delete controller; <-- Crashea al final del deconstructor y no se porque
    return 0;
}
