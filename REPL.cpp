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
        if ( cmnd == "help" )
            PrintHelp ( );
        if ( cmnd == "update" );
    }
    return true;
}

void REPL::Eval ( void ) {

}

void REPL::PrintHelp ( void ) {
    std::cout << "update - Inserts match into database"
        << "\nexit - Exits the program"
        << std::endl;
}