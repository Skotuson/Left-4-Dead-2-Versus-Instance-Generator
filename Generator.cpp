#include <fstream>

#include "Generator.h"

void Generator::Load ( const std::string & filename ) {
    std::ifstream ifs ( filename );
    
    ifs . close ( );
}