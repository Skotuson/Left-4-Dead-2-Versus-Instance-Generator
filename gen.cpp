#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <cmath>

template <class T_>
void Print ( const std::vector<T_> & v ) {
    for ( const auto & x : v ) 
        std::cout << x << " ";
    std::cout << std::endl;
}

template <class T_>
std::vector<T_> Fisher_Yates ( const std::vector<T_> & cards ) {
    srand ( time ( nullptr ) );
    std::vector<T_> shuffled = cards;
    for ( size_t i = 0; i < cards . size(); i++ ) {
        size_t j = rand() % ( i + 1 );
        T_ tmp = shuffled[i];
        shuffled[i] = shuffled[j];
        shuffled[j] = tmp;
    }
    return shuffled;
}

int main ( void ) {
    std::ifstream ifs ( "in.txt" );
    size_t team_one, team_two, team_total;

    ifs >> team_one >> team_two;
    team_total = team_one + team_two;

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
        }
    }

    std::vector<std::string> players;
    while ( team_total-- ) {
        std::string player;
        ifs >> player;
        players . push_back ( player );
    }

    std::vector<std::string> players_shuffled = Fisher_Yates ( players );

    std::cout << "Survivors:" << std::endl; 
    for ( size_t i = 0; i < team_one; i++ ) 
        std::cout << players_shuffled[i] << " ";
    std::cout << std::endl;

    std::cout << "Infected:" << std::endl; 
    for ( size_t i = team_one; i < team_one + team_two; i++ ) 
        std::cout << players_shuffled[i] << " ";
    std::cout << std::endl;

    //std::vector<std::string> a = { "Francis", "Louis", "Rochelle", "Zoey", "Bill", "Nick", "Ellis", "Coach" };
    //Print ( a );
    //for ( size_t i = 0; i < 15; i++ ) {
    //    usleep ( 1'000'000 );
    //    Print<std::string> ( Fisher_Yates<std::string> ( a ) );
    //}
    return 0;
}