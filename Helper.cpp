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

std::vector<std::string> Fisher_Yates ( const std::vector<std::string> & cards ) {
    srand ( time ( nullptr ) );
    std::vector<std::string> shuffled = cards;
    for ( size_t i = 0; i < cards . size(); i++ ) {
        size_t j = rand() % ( i + 1 );
        std::string tmp = shuffled[i];
        shuffled[i] = shuffled[j];
        shuffled[j] = tmp;
    }
    return shuffled;
}