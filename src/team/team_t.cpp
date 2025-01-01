#include "team_t.h"

void team_t::player_add(player_t const &player)
{
    teammates_.insert(player);
}