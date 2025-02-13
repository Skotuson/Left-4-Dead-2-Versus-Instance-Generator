#include "team_t.h"

void team_t::player_add(player_t const &player)
{
    teammates_.insert(player);
}

std::optional<player_t> const team_t::player_get(player_t::player_id_t const &id) const
{
    auto it = teammates_.find(player_t(id));
    if (it == teammates_.end())
    {
        return std::nullopt;
    }
    return *it;
}

bool team_t::operator<(team_t const &team) const
{
    return teammates_ < team.teammates_;
}

std::ostream &operator<<(std::ostream &os, team_t const &team)
{
    bool first = true;
    for (auto const &player : team)
    {
        if (!first)
        {
            os << " ";
        }

        os << player.identifier();

        first = false;
    }
    return os;
}