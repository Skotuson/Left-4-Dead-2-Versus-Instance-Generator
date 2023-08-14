#include <iostream>

#include "REPL.h"

void REPL::Run ( void ) {
    std::cout << "Welcome to the L4D2 Instance Generator interactive mode. Use the \"help\" to learn more commands" << std::endl;
    std::cout << " > ";
    while ( Read ( ) ) {
        Eval ( );
    }
}

bool REPL::Read ( void ) {

    return false;
}

void REPL::Eval ( void ) {

}