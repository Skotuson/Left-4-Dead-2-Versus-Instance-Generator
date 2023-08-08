#include <fstream>

#include "Generator.h"

void Generator::Load ( const std::string & filename ) {
    std::ifstream ifs ( filename );
    std::string player;
    while ( ifs >> player ) {
        m_Total++;
        m_Players . push_back ( player );
    }
    ifs . close ( );
}