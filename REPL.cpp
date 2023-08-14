#include <iostream>

#include "REPL.h"

void REPL::Run ( void ) {
    std::cout << "Welcome to the L4D2 Instance Generator interactive mode.\nUse the \"help\" to learn more commands" << std::endl;
    while ( Read ( ) ) {
        Eval ( );
    }
}

bool REPL::Read ( void ) {
    std::string cmnd = "";
    while ( 1 ) {
        std::cout << "> ";
        if ( ! ( std::cin >> cmnd ) || cmnd == "exit" )
            return false;
    }
    return true;
}

void REPL::Eval ( void ) {

}