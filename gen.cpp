#include <iostream>
#include <cstring>
#include <memory>

#include "Generator.h"
#include "Database.h"
#include "Helper.h"
#include "REPL.h"

int main ( int argc, char * argv [] ) {
    Database * db = new Database ( "save.txt" );
    db -> Load ( );

    if ( argc > 1 && argc < 3 ) {
        if ( ! strcmp ( argv[1], "-stat" ) )
            db -> PrintPlayerStats ( );

        else if ( ! strcmp ( argv[1], "-update" ) ) {
            std::cout << "> ";
            db -> Add ( std::cin );
            db -> Save ( );
        }

        else if ( ! strcmp ( argv[1], "-team" ) )
            db -> PrintTeammates ( );
        
        else if ( ! strcmp ( argv[1], "-interactive" ) ) {
            REPL repl ( db );
            repl . Run ( );
        }

        else {
            std::cout << "Invalid flag" << std::endl;
            delete db;
            return 1;
        }

        delete db;
        return 0;
    } else if ( argc >= 2 ) {
        std::cout << "Missing -flag" << std::endl; 
        return 1;
    }
    
    db -> Save ( );

    Generator gen;
    gen . Load ( "in.txt" );
    std::cout << "Random shuffle:" << std::endl;
    gen . GenerateRandom ( db );

    std::cout << "\"Fair\" shuffle:" << std::endl;
    gen . GenerateFair ( db );
    
    gen . GenerateMap ( );

    delete db;

    return 0;
}