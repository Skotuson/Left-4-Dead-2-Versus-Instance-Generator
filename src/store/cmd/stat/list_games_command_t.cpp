#include "list_games_command_t.h"

list_games_command_t::list_games_command_t(database_t::matches_t const &matches)
    : matches_(matches)
{
}

void list_games_command_t::execute(database_t &db) const
{
    // TODO: handle better, quick hack for now
    if (!matches_.empty())
    {
        for (auto const &match : matches_)
        {
            std::cout << match << std::endl;
        }
        return;
    }

    for (auto const &match : db.matches_get())
    {
        std::cout << match << std::endl;
    }
}