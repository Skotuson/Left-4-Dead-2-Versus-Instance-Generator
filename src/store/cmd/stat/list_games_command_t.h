#pragma once

#include "../command_t.h"

struct list_games_command_t : command_t
{
    list_games_command_t(database_t::matches_t const &matches = {});
    void execute(database_t &db) const;

private:
    database_t::matches_t matches_;
};