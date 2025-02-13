#include "add_match_command_t.h"

add_match_command_t::add_match_command_t(match_t const &match)
    : match_(match)
{
}

void add_match_command_t::execute(database_t &db) const
{
    db.match_add(match_);
}