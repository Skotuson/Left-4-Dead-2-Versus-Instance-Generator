#include "player_t.h"

size_t player_t::inc_played(size_t played = 1)
{
    n_played += played;
}

size_t player_t::inc_won(size_t won = 1)
{
    n_won += won;
}