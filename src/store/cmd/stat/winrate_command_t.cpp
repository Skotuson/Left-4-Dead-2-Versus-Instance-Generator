#include "winrate_command_t.h"

#include <iomanip>

void winrate_command_t::execute(database_t &db) const
{
    for (auto const &player : db.players_get())
    {
        size_t won = 0;
        size_t games_total = 0;
        for (auto const &match : db.matches_get())
        {
            if (!match.played(player))
            {
                continue;
            }

            games_total++;

            if (match.won(player))
            {
                won++;
            }
        }

        // TODO: add generic stream later
        std::cout << player.identifier() << " won " << won << " out of " << games_total << " games"
                  << std::setprecision(PRINT_PRECISION_) << " (" << (won / (double)games_total) * 100.0 << "%)" << std::endl;
    }
}