#pragma once

#include "../command_t.h"

struct filter_games_season_command_t : command_t
{
    filter_games_season_command_t(std::string const &season_name);
    void execute(database_t &db) const;

private:
    std::string season_name_;
};