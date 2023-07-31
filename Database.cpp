#include "Database.h"
#include "Helper.h"

Database::Database ( const std::string & filename )
: m_Source ( filename )
{}

void Database::SetSource ( const std::string & filename ) {
    m_Source = filename;
}

void Database::Load ( void ) {
    std::ifstream ifs ( m_Source );

    ifs . close ( );
}

size_t Database::GetGames ( void ) {
    return m_Games;
}

void Database::PlayerStats ( void ) {

}

void Database::TeamStats ( void ) {
    
}

bool Database::ParseEntry ( std::ifstream & ifs ) {
    std::string tok;
    std::set<std::string> team_a, 
                          team_b;
    //Parse flags
    bool team = false,
         colon = false;
    
    while ( ifs >> tok ) {
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
                return true;
            } 
            else {
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

void Database::UpdateTeam ( const std::set<std::string> & team, size_t val ) {
    auto it = m_Teams . find ( team );
    if ( it == m_Teams . end ( ) )
        m_Teams . insert ( { team, val } );
    else it -> second += val;
}

void Database::UpdatePlayer ( const std::set<std::string> & team, size_t val ) {
    for ( const auto & elem : team ) {
        auto it = m_Players . find ( elem );
        if ( it == m_Players . end ( ) )
            m_Players . insert ( { elem, val } );
        else it -> second += val;
    }
}