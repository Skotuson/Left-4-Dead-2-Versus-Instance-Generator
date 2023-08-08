#include <fstream>
#include <cmath>

#include "Generator.h"

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