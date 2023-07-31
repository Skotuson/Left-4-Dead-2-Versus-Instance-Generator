#include "Database.h"

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

bool Database::ParseEntry ( std::ifstream & ifs ) {
    std::string tok;
    std::set<std::string> team_a, 
                          team_b;
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
                //update_players_score ( team_b, players_score, val );
                //update_team_score ( teams_score, team_b, val );
                return true;
            } 
            else {
                //update_players_score ( team_a, players_score, val );
                //update_team_score ( teams_score, team_a, val );
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
