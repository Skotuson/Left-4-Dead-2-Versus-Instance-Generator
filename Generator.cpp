#include <iostream>
#include <unistd.h>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "Generator.h"
#include "Helper.h"

void Generator::Load ( const std::string & filename ) {
    std::ifstream ifs ( filename );
    std::string player;
    while ( ifs >> player )
        m_Players . push_back ( player );
    ifs . close ( );

    if ( m_Players . size ( ) > 8 ) {
        m_TeamOne = 4;
        m_TeamTwo = 4;
    }

    else if ( m_Players . size ( ) < 8 ) {
        srand ( time ( nullptr ) );
        //Flip a coin :-)
        int coin = rand ( ) % 2;
        if ( ! coin ) {
            m_TeamOne = std::ceil  ( m_Players . size ( ) / 2.0 );
            m_TeamTwo = std::floor ( m_Players . size ( ) / 2.0 );
        } else {
            m_TeamOne = std::floor ( m_Players . size ( ) / 2.0 );
            m_TeamTwo = std::ceil  ( m_Players . size ( ) / 2.0 );
        }
    }
}

std::vector<Player> Generator::GetPlayers ( void ) {
    return m_Players;
}

void Generator::GenerateRandom ( Database & db ) {
    std::vector<Player> players_shuffled = Fisher_Yates ( m_Players );

    std::cout << "Survivors:" << std::endl; 
    for ( size_t i = 0; i < m_TeamOne; i++ ) 
        std::cout << players_shuffled[i] << std::setprecision ( PRINT_PRECISION ) << " [" << db . GetPlayerPercentage ( players_shuffled[i] ) << "%]" << " ";
    std::cout << std::endl;

    std::cout << "Infected:" << std::endl; 
    for ( size_t i = m_TeamOne; i < m_TeamOne + m_TeamTwo; i++ ) 
        std::cout << players_shuffled[i] << std::setprecision ( PRINT_PRECISION ) << " [" << db . GetPlayerPercentage ( players_shuffled[i] ) << "%]" << " ";
    std::cout << std::endl << std::endl;
}

void Generator::GenerateFair ( Database & db ) {
    std::vector<Player> players_shuffled ( m_Players . size ( ) );
    int lo = 0, hi = m_Players . size ( ) - 1;

    for ( size_t i = 0; i < m_Players . size ( ); i++ )
        if ( get_parity ( i ) )
            players_shuffled[lo++] = m_Players[i];
        else players_shuffled[hi--] = m_Players[i];

    std::cout << "Survivors:" << std::endl; 
    for ( size_t i = 0; i < m_TeamOne; i++ ) 
        std::cout << players_shuffled[i] << std::setprecision ( PRINT_PRECISION ) << " [" << db . GetPlayerPercentage ( players_shuffled[i] ) << "%]" << " ";
    std::cout << std::endl;

    std::cout << "Infected:" << std::endl; 
    for ( size_t i = m_TeamOne; i < m_TeamOne + m_TeamTwo; i++ ) 
        std::cout << players_shuffled[i] << std::setprecision ( PRINT_PRECISION ) << " [" << db . GetPlayerPercentage ( players_shuffled[i] ) << "%]" << " ";
    std::cout << std::endl << std::endl;
}

void Generator::GenerateMap ( void ) {
    srand( time ( nullptr ) );
    std::string map = MAPS[rand() % MAPS . size()];
    std::cout << "Map: " << map << std::endl;
    while ( REROLL . count ( map ) ) {
        std::cout << "Cringe Map, Rerolling..." << std::endl;
        usleep ( 750'000 );
        map = MAPS[rand() % MAPS . size()];
        std::cout << "Map: " << map << std::endl;
    }
}

