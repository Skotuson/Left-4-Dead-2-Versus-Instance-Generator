#pragma once

#include "../command_t.h"
#include "../../player/player_t.h"

struct player_weight_command_t : command_t
{
    player_weight_command_t(player_t const & player);
    void execute(database_t &db) const;

private:
    player_t player_;
};