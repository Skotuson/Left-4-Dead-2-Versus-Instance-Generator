#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

bool                     is_numeric   ( const std::string              & str );
void                     print_set    ( const std::set<std::string>    & Set );
std::vector<std::string> Fisher_Yates ( const std::vector<std::string> & cards );

#endif