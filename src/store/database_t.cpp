#include "database_t.h"

void database_t::player_add(player_t const &player)
{
    players_.insert(player);
}

void database_t::team_add(team_t const &team)
{
    teams_.insert(team);
}

void database_t::match_add(match_t const &match)
{
    matches_.insert(match);
}

database_t::players_t const &database_t::players_get(void)
{
    return players_;
}

database_t::teams_t const &database_t::teams_get(void)
{
    return teams_;
}

database_t::matches_t const &database_t::matches_get(void)
{
    return matches_;
}