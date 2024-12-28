#pragma once

#include <iostream>
#include <vector>
#include <set>

#include "../player/player_t.h"
#include "../match/match_t.h"
#include "../team/team_t.h"

struct database_t
{
    database_t(void) = default;

    void load(std::istream &is);
    void save(std::ostream &os);

private:
    std::set<player_t> players_;
    std::set<team_t> teams_;
    std::vector<match_t> matches_;
};