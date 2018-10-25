#include <iostream>
#include <string>

#include "interface.h"

int main() {
    Interface* interface = new Interface;
    interface->mainMenu();

    //delete interface; <- crashea el programa y no se porque

    return 0;
}
