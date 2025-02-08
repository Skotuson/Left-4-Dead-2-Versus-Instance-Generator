#pragma once

#include "../command_t.h"
#include "../../player/player_t.h"

struct player_weight_command_t : command_t
{
    enum weight_algorithm_t
    {
        WINRATE,
        WEIGHTED,
        ELO
    };

    player_weight_command_t(player_t const &player, weight_algorithm_t const &weight_algorithm = WINRATE);
    void execute(database_t &db) const;

private:
    player_t player_;
    weight_algorithm_t weight_algorithm_;
};