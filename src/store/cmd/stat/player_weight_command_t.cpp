#include "player_weight_command_t.h"

player_weight_command_t::player_weight_command_t(player_t const &player,
                                                 player_weight_command_t::weight_algorithm_t const &weight_algorithm)
    : player_(player),
      weight_algorithm_(weight_algorithm)
{
}

void player_weight_command_t::execute(database_t &db) const
{
}