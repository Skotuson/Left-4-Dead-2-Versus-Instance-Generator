#include "player_t.h"

player_t::player_t(player_t::player_id_t const &identifier)
    : identifier_(identifier)
{
}

player_t::player_id_t const &player_t::identifier(void) const
{
    return identifier_;
}

size_t player_t::played(void) const
{
    return n_played_;
}

size_t player_t::won(void) const
{
    return n_won_;
}

void player_t::inc_played(size_t played)
{
    n_played_ += played;
}

void player_t::inc_won(size_t won)
{
    n_won_ += won;
}

bool player_t::operator<(player_t const &player) const
{
    return identifier() < player.identifier();
}