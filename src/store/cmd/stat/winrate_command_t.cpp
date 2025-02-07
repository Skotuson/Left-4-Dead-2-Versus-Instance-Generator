#include "winrate_command_t.h"

void winrate_command_t::execute(database_t &db) const
{
    for (auto const &player : db.players_get())
    {
        size_t won = 0;
        size_t games_total = 0;
        for (auto const &match : db.matches_get())
        {
            
        }

        std::cout << player.identifier() << " won " << won << " out of " << games_total << " games" << std::endl;
    }
}