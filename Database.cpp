#include <fstream>

#include "Database.h"

Database::Database ( const std::string & filename )
: m_Source ( filename )
{}

void Database::Set_Source ( const std::string & filename ) {
    m_Source = filename;
}

void Database::Load ( void ) {
    std::ifstream ifs ( m_Source );

    ifs . close ( );
}