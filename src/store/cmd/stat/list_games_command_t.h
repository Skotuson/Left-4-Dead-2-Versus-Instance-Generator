#pragma once

#include "../command_t.h"

struct list_games_command_t : command_t
{
    void execute(database_t &db) const;
};