#include <iostream>
#include <string>

#include "REPL.h"

void REPL::Run ( void ) {
    std::cout << "Welcome to the L4D2 Instance Generator interactive mode.\nUse the \"help\" to learn more commands" << std::endl;
    while ( Read ( ) ) {
        Eval ( );
    }
}

bool REPL::Read ( void ) {
    std::string cmnd;
    do {
        std::cout << "> ";
    } while ( std::cin >> cmnd && cmnd != "exit" );
    return false;
}

void REPL::Eval ( void ) {

}