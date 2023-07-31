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

const std::vector <std::string> MAPS = {
    "No Mercy", "Crash Course", "Death Toll", "Dead Air", "Blood Harvest", "The Sacrifice", "The Last Stand",
    "Dead Center", "The Passing", "Dark Carnival", "Swamp Fever", "Hard Rain", "The Parish", "Cold Stream"
};

const std::set <std::string> REROLL = {
    "Crash Course", "The Sacrifice", "The Last Stand", "The Passing"
};

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

bool is_numeric ( const std::string & str ) {
    for ( const auto & c : str )
        if ( ! isdigit ( c ) )
            return false;
    return true;
}

void print_set ( const std::set<std::string> & Set ) {
    std::cout << "{ ";
    for ( const auto & elem : Set )
        std::cout << elem << " ";
    std::cout << "}";
}

void print_team_score ( const std::map<std::set<std::string>, size_t> & table ) {
    for ( const auto & elem : table ) {
        print_set ( elem . first );
        std::cout << " -> " << elem . second << std::endl;
    }
}

void print_player_score ( const std::map<std::string, size_t> & table ) {
    for ( const auto & elem : table )
        std::cout << elem . first << " -> " << elem . second << std::endl;
}

void update_team_score ( std::map<std::set<std::string>, size_t> & table, 
                         const std::set<std::string> & elem,
                         size_t amount ) 
{
    auto it = table . find ( elem );
    if ( it == table . end ( ) )
        table . insert ( { elem, amount } );
    else it -> second += amount;
}

void update_players_score ( std::set<std::string> & players,
                           std::map<std::string, size_t> & table, 
                           size_t amount ) 
{
    for ( const auto & elem : players ) {
        auto it = table . find ( elem );
        if ( it == table . end ( ) )
            table . insert ( { elem, amount } );
        else it -> second += amount;
    }
}

bool parse_entry ( std::ifstream & ifs,
                   size_t                        & games,
                   std::map<std::string, size_t> & players_score,
                   std::map<std::set<std::string>, size_t> & teams_score ) 
{
    //Score counting
    std::string tok;
    std::set<std::string> team_a;
    std::set<std::string> team_b;
    bool team = false;
    bool colon = false;
    while ( ifs >> tok ) {
        //second team starts
        if ( tok == "x" )
            team = true;
        
        //teams have been parsed
        else if ( tok == "-" ) {   
        }

        //lexed number
        else if ( is_numeric ( tok ) ) {
            //second team score
            size_t val = std::stoi ( tok );
            games += val;
            if ( colon ) {
                update_players_score ( team_b, players_score, val );
                update_team_score ( teams_score, team_b, val );
                return true;
            } 
            else {
                update_players_score ( team_a, players_score, val );
                update_team_score ( teams_score, team_a, val );
            }
        }

        else if ( tok == ":" ) colon = true;

        else {
            if ( team ) team_b . insert ( tok );
            else team_a . insert ( tok );
        }    
    }
    return false;
}

int main ( int argc, char * argv [] ) {
    if ( argc > 1 && argc < 3 ) {
        if ( ! strcmp ( argv[1], "-stat" ) ) {
            
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

    ifs . open ( "score.txt" );
    std::map<std::string, size_t> players_score;
    std::map<std::set<std::string>, size_t> teams_score;
    size_t games = 0;
    while ( parse_entry ( ifs, games, players_score, teams_score ) );
    ifs . close ( );

    //std::cout << games << std::endl;
    //print_player_score ( players_score );
    //print_team_score ( teams_score );

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
        std::cout << players_shuffled[i] << " [" << ( players_score[players_shuffled[i]] / (double ) games ) * 100.0 << "%]" << " ";
    std::cout << std::endl;

    std::cout << "Infected:" << std::endl; 
    for ( size_t i = team_one; i < team_one + team_two; i++ ) 
        std::cout << players_shuffled[i] << " [" << ( players_score[players_shuffled[i]] / (double ) games ) * 100.0 << "%]" << " ";
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

    //std::vector<std::string> a = { "Francis", "Louis", "Rochelle", "Zoey", "Bill", "Nick", "Ellis", "Coach" };
    //Print ( a );
    //for ( size_t i = 0; i < 15; i++ ) {
    //    usleep ( 1'000'000 );
    //    Print<std::string> ( Fisher_Yates<std::string> ( a ) );
    //}
    return 0;
}