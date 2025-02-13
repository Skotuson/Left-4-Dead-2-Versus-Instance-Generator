#pragma once

#include "../command_t.h"

#include "../../../match/match_t.h"

struct add_match_command_t : command_t
{
    add_match_command_t(match_t const &match);
    void execute(database_t &db) const;

private:
    match_t match_;
};