#include <cmath>
#include <cfloat>

#include "Helper.h"

bool is_numeric ( const std::string & str ) {
    for ( const auto & c : str )
        if ( ! isdigit ( c ) )
            return false;
    return true;
}

bool eps_equal ( double a, double b ) {
    return fabs ( a - b ) <= DBL_EPSILON * ( fabs ( a ) + fabs ( b ) );
}

void print_set ( const std::set<std::string> & Set, bool brackets,  std::ostream & os ) {
    if ( brackets )
        os << "{ ";
    for ( const auto & elem : Set )
        os << elem << " ";
    if ( brackets )
        os << "}";
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

bool get_parity ( int n ) {
    bool parity = 0;
    while ( n ) {
        parity = ! parity;
        //Remove the rightmost bit
        n      = n & ( n - 1 );
    }
    
    return parity;
}