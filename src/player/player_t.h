#pragma once

#include <string>

struct player_t
{
    player_t(std::string const &identifier);

    size_t inc_played(size_t played = 1);
    size_t inc_won(size_t won = 1);

private:
    std::string identifier_;
    size_t n_played;
    size_t n_won;
};