#pragma once

#include <set>

#include "../player/player_t.h"
#include "../team/team_t.h"

struct database_t
{
    database_t(void) = default;

private:
    std::set<player_t> players_;
    std::set<team_t> teams_;
};