#include "player_t.h"

player_t::player_t(std::string const &identifier)
    : identifier_(identifier)
{
}

size_t player_t::played(void)
{
    return n_played_;
}

size_t player_t::won(void)
{
    return n_won_;
}

void player_t::inc_played(size_t played = 1)
{
    n_played_ += played;
}

void player_t::inc_won(size_t won = 1)
{
    n_won_ += won;
}