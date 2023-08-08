#include <iomanip>
#include <iostream>

#include "Helper.h"
#include "Database.h"

Database::Database ( const std::string & filename )
: m_Source ( filename )
{}

void Database::SetSource ( const std::string & filename ) {
    m_Source = filename;
}

void Database::Add ( std::istream & is ) {
    ParseEntry ( is );
}

void Database::Load ( void ) {
    std::ifstream ifs ( m_Source );
    while ( ParseEntry ( ifs ) );
    ifs . close ( );
}

void Database::Save ( void ) {
    std::ofstream ofs ( "save.txt" );
    PrintMatches ( ofs );
    ofs . close ( );
}

size_t Database::GetGames ( void ) {
    return m_Games;
}

size_t Database::GetPlayerGames ( const std::string & player ) {
    size_t r = 0;
    for ( const auto & m : m_Matches ) 
        for ( const auto & team : m . first ) 
            if ( team . count ( player ) ) r++;
    return r;
}

double Database::GetPlayerPercentage ( const std::string & player ) {
    return ( m_Players[player] / (double) GetPlayerGames ( player ) ) * 100.0;
}

void Database::PrintPlayerStats ( void ) {
    for ( const auto & elem : m_Players )
        std::cout << elem . first << " won " << std::setprecision ( 3 ) << elem . second << " out of " << GetPlayerGames ( elem . first ) << " (" << GetPlayerPercentage ( elem . first ) << "%)" << std::endl;
}

void Database::PrintTeamStats ( void ) {
    for ( const auto & elem : m_Teams ) {
        print_set ( elem . first );
        std::cout << " -> " << elem . second << std::endl;
    }
}

void Database::PrintMatches ( std::ostream & os ) {
    for ( const auto & elem : m_Matches ) {
        auto it = elem . first . begin ( );
        print_set ( *it, false, os );
        std::advance ( it, 1 );
        os << "x ";
        print_set ( *it, false, os );
        os << "- " << elem . second . first << " : " << elem . second . second << std::endl;
    }
}

bool Database::ParseEntry ( std::istream & is ) {
    std::string tok;
    std::set<std::string> team_a, 
                          team_b;

    std::pair<std::set<Team>, Score> match;
    //Parse flags
    bool team = false,
         colon = false;
    
    while ( is >> tok ) {
        //Teams delimiter parsed
        if ( tok == "x" ) team = true;
        //Teams and score delimiter parsed
        else if ( tok == "-" ) continue; 

        //lexed number
        else if ( is_numeric ( tok ) ) {
            //second team score
            size_t val = std::stoi ( tok );
            m_Games += val;
            if ( colon ) {
                UpdatePlayer ( team_b, val );
                UpdateTeam   ( team_b, val );
                std::set<Team> teams = { team_a, team_b };
                match . first = teams;
                match . second . second = val;
                //In case the first team is lexicographically greater, swap the score.
                if ( team_a > team_b )
                    std::swap ( match . second . first, match . second . second );
                auto it = m_Matches . find ( match . first );
                if ( it != m_Matches . end ( ) ) {
                    it -> second . first  += match . second . first;
                    it -> second . second += match . second . second;
                }
                else m_Matches . insert ( match );
                return true;
            } 
            else {
                match . second . first = val;
                UpdatePlayer ( team_a, val );
                UpdateTeam   ( team_a, val );
            }
        }

        //Score delimiter parsed
        else if ( tok == ":" ) colon = true;

        else {
            if ( team ) team_b . insert ( tok );
            else team_a . insert ( tok );
        }    
    }

    //All entries were parsed
    return false;
}

void Database::UpdateTeam ( const Team & team, size_t val ) {
    auto it = m_Teams . find ( team );
    if ( it == m_Teams . end ( ) )
        m_Teams . insert ( { team, val } );
    else it -> second += val;
}

void Database::UpdatePlayer ( const Team & team, size_t val ) {
    for ( const auto & elem : team ) {
        auto it = m_Players . find ( elem );
        if ( it == m_Players . end ( ) )
            m_Players . insert ( { elem, val } );
        else it -> second += val;
    }
}