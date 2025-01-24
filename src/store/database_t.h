#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <set>

#include "../player/player_t.h"
#include "../match/match_t.h"
#include "../team/team_t.h"

struct database_t
{
    static inline std::regex const & OLD_DB_FORMAT = std::regex(R"((.+?)\s+x\s+(.+?)\s+-\s+(\d+)\s*:\s*(\d+))");

    using players_t = std::set<player_t>;
    using teams_t = std::set<team_t>;
    using matches_t = std::vector<match_t>;

    void player_add(player_t const & player);
    void team_add(team_t const & team);
    void match_add(match_t const & match);

    players_t const & players_get(void) const;
    teams_t const & teams_get(void) const;
    matches_t const & matches_get(void) const;

private:
    players_t players_;
    teams_t teams_;
    matches_t matches_;
}; // database_t