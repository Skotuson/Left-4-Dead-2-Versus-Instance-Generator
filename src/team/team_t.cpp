#include "team_t.h"

void team_t::player_add(player_t const &player)
{
    teammates_.insert(player);
}

player_t const &team_t::player_get(player_t::player_id_t const &id)
{
    auto it = teammates_.find(player_t(id));
    if (it == teammates_.end())
    {
        // TODO: throw error
    }
    return *it;
}

bool team_t::operator<(team_t const &team) const
{
    return teammates_ < team.teammates_;
}