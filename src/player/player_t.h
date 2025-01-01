#pragma once

#include <string>

struct player_t
{
    player_t(std::string const &identifier);

    size_t played(void);
    size_t won(void);

    void inc_played(size_t played = 1);
    void inc_won(size_t won = 1);

private:
    std::string identifier_;
    size_t n_played_;
    size_t n_won_;
};