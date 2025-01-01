#pragma once

#include <string>

struct player_t
{
    using player_id_t = std::string;

    player_t(player_id_t const &identifier);

    size_t played(void);
    size_t won(void);

    void inc_played(size_t played = 1);
    void inc_won(size_t won = 1);

private:
    player_id_t identifier_;
    size_t n_played_;
    size_t n_won_;
};