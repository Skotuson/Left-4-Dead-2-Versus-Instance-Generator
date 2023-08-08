#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Generator.h"
#include "Database.h"
#include "Helper.h"

const std::vector <std::string> MAPS = {
    "No Mercy", "Crash Course", "Death Toll", "Dead Air", "Blood Harvest", "The Sacrifice", "The Last Stand",
    "Dead Center", "The Passing", "Dark Carnival", "Swamp Fever", "Hard Rain", "The Parish", "Cold Stream"
};

const std::set <std::string> REROLL = {
    "Crash Course", "The Sacrifice", "The Last Stand", "The Passing"
};

int main ( int argc, char * argv [] ) {
    Database db ( "save.txt" );
    db . Load ( );

    if ( argc > 1 && argc < 3 ) {
        if ( ! strcmp ( argv[1], "-stat" ) ) {
            db . PrintPlayerStats ( );
            return 0;
        }

        else if ( ! strcmp ( argv[1], "-update" ) ) {
            std::cout << "> ";
            db . Add ( std::cin );
            db . Save ( );
            return 0;
        }

        else {
            std::cout << "Invalid flag" << std::endl;
            return 1;
        }
        return 0;
    } else if ( argc >= 2 ) {
        std::cout << "Missing -flag" << std::endl; 
        return 1;
    }

    db . Save ( );

    Generator gen;

    gen . Load ( "in.txt" );

    std::cout << "Random shuffle:" << std::endl;
    gen . GenerateRandom ( db );

    srand( time ( nullptr ) );
    std::string map = MAPS[rand() % MAPS . size()];
    std::cout << "Map: " << map << std::endl;
    while ( REROLL . count ( map ) ) {
        std::cout << "Cringe Map, Rerolling..." << std::endl;
        usleep ( 750'000 );
        map = MAPS[rand() % MAPS . size()];
        std::cout << "Map: " << map << std::endl;
    }

    return 0;
}