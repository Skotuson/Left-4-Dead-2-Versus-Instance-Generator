#include "filter_games_season_command_t.hpp"
#include "winrate_command_t.h"

#include <fstream>

filter_games_season_command_t::filter_games_season_command_t(std::string const &season_name)
    : season_name_(season_name)
{
}

void filter_games_season_command_t::execute(database_t &db) const
{
    // TODO: make more modular using other commands later
    std::ifstream ifs("config/season.config");

    match_t::timestamp_t season_timestamp = {};

    std::string line;
    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);
        std::string name, timestamp;
        iss >> name >> timestamp;
        if(name == season_name_) {
            season_timestamp = std::chrono::system_clock::time_point(std::chrono::seconds(std::stoll(timestamp)));
            break;
        }
    }

    database_t db_filtered;
    for(auto const & match : db.matches_get()) {
        if(match.timestamp() >= season_timestamp) {
            db_filtered.match_add(match);
        }
    }

    std::cout << "Season: " << season_name_ << std::endl;

    std::make_shared<winrate_command_t>()->execute(db_filtered);
}