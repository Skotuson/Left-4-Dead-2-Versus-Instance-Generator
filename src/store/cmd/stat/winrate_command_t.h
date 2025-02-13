#pragma once

#include "../command_t.h"

struct winrate_command_t : command_t
{
    void execute(database_t &db) const;

private:
    size_t const PRINT_PRECISION_ = 4;
};