#pragma once

#include "../database_t.h"

struct command_t
{
    virtual void execute(database_t &db) const = 0;
}; // command_t