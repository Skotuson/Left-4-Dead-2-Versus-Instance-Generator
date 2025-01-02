#include "text_stream_old_format_database_saver_t.h"

#include <fstream>
#include <map>

text_stream_old_format_database_saver_t::text_stream_old_format_database_saver_t(std::string const &filename)
    : stream_old_format_database_saver_t(std::make_unique<std::ofstream>(filename))
{
}

void text_stream_old_format_database_saver_t::save(database_t const &database)
{
    std::map<std::pair<team_t, team_t>, std::pair<size_t, size_t>> mapping;
    for (auto const &match : database.matches_get())
    {
        auto team_pair = std::make_pair(match.first(), match.second());

        auto it = mapping.find(team_pair);
        if (it == mapping.end())
        {
            mapping.insert({team_pair, {match.outcome() == match_t::outcome_t::FIRST_TEAM_WON, match.outcome() == match_t::outcome_t::FIRST_TEAM_WON}});
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

    for (auto const &record : mapping)
    {
        *underlying_ << record.first.first << " x " << record.first.second << " - " << record.second.first << " : " << record.second.first << std::endl;
    }
}