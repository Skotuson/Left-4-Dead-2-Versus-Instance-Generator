#pragma once

#include "../command_t.h"

struct winrate_command_t : command_t
{
    void execute(database_t &db) const;
};