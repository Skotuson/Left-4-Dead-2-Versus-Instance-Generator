#include "list_seasons_command_t.hpp"

#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

list_seasons_command_t::list_seasons_command_t(void)
{
}

void list_seasons_command_t::execute(database_t &db) const
{
    std::ifstream ifs("config/season.config");

    // TODO: better check
    assert(ifs);

    std::string line;
    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);
        std::string name, timestamp;
        iss >> name >> timestamp;
        std::cout << "Season " << name << ", start: " << timestamp << std::endl;
    }
}