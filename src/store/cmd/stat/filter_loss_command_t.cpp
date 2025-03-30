#include "filter_loss_command_t.h"
#include "list_games_command_t.h"

#include <memory>

filter_loss_command_t::filter_loss_command_t(std::string const &player)
    : player_(player)
{
}

void filter_loss_command_t::execute(database_t &db) const
{
    database_t::matches_t filtered_matches;   
    for (auto const &match : db.matches_get()) {
        if(!match.won(player_) && match.played(player_)) {
            filtered_matches.push_back(match);
        }
    }

    std::make_shared<list_games_command_t>(filtered_matches)->execute(db);
}