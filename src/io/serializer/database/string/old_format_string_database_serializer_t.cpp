#include "old_format_string_database_serializer_t.h"

#include <sstream>

std::string old_format_string_database_serializer_t::serialize(database_t const &database) const
{
    std::map<std::pair<team_t, team_t>, std::pair<size_t, size_t>> mapping;
    for (auto const &match : database.matches_get())
    {
        auto team_pair = std::make_pair(match.first(), match.second());

        auto it = mapping.find(team_pair);
        if (it == mapping.end())
        {
            mapping.insert({team_pair, {match.outcome() == match_t::outcome_t::FIRST_TEAM_WON, match.outcome() == match_t::outcome_t::SECOND_TEAM_WON}});
        }

        else if (match.outcome() == match_t::outcome_t::FIRST_TEAM_WON)
        {
            it->second.first += 1;
        }

        else if (match.outcome() == match_t::outcome_t::SECOND_TEAM_WON)
        {
            it->second.second += 1;
        }
    }

    std::ostringstream result("");
    for (auto const &record : mapping)
    {
        result << record.first.first << " x " << record.first.second << " - " << record.second.first << " : " << record.second.second << std::endl;
    }

    return result.str();
}