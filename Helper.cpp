#include "Helper.h"

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