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
#include <algorithm>

#include "Database.h"

const std::vector <std::string> MAPS = {
    "No Mercy", "Crash Course", "Death Toll", "Dead Air", "Blood Harvest", "The Sacrifice", "The Last Stand",
    "Dead Center", "The Passing", "Dark Carnival", "Swamp Fever", "Hard Rain", "The Parish", "Cold Stream"
};

const std::set <std::string> REROLL = {
    "Crash Course", "The Sacrifice", "The Last Stand", "The Passing"
};

std::vector<std::string> Fisher_Yates ( const std::vector<std::string> & cards ) {
    srand ( time ( nullptr ) );
    std::vector<std::string> shuffled = cards;
    for ( size_t i = 0; i < cards . size(); i++ ) {
        size_t j = rand() % ( i + 1 );
        std::string tmp = shuffled[i];
        shuffled[i] = shuffled[j];
        shuffled[j] = tmp;
    }
    return shuffled;
}

int main ( int argc, char * argv [] ) {
    Database db ( "score.txt" );
    db . Load ( );

    if ( argc > 1 && argc < 3 ) {
        if ( ! strcmp ( argv[1], "-stat" ) ) {
            db . PlayerStats ( );
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

    std::vector<std::string> players;
    std::string player;
    size_t team_one = 4, team_two = 4, team_total = 0;
    std::ifstream ifs ( "in.txt" );
    while ( ifs >> player ) {
        team_total++;
        players . push_back ( player );
    }

    ifs . close ( );

    if ( team_total > 8 ) {
        team_one = 4;
        team_two = 4;
    }

    else if ( team_total < 8 ) {
        srand ( time ( nullptr ) );
        int coin = rand() % 2;
        if ( ! coin ) {
            team_one = std::ceil ( team_total / 2.0 );
            team_two = std::floor ( team_total / 2.0 );
        } else {
            team_one = std::floor ( team_total / 2.0 );
            team_two = std::ceil ( team_total / 2.0 );
        }
    }

    std::vector<std::string> players_shuffled = Fisher_Yates ( players );

    std::cout << "Survivors:" << std::endl; 
    for ( size_t i = 0; i < team_one; i++ ) 
        std::cout << players_shuffled[i] << " [" << db . GetPlayerPercentage ( players_shuffled[i] ) << "%]" << " ";
    std::cout << std::endl;

    std::cout << "Infected:" << std::endl; 
    for ( size_t i = team_one; i < team_one + team_two; i++ ) 
        std::cout << players_shuffled[i] << " [" << db . GetPlayerPercentage ( players_shuffled[i] ) << "%]" << " ";
    std::cout << std::endl << std::endl;

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