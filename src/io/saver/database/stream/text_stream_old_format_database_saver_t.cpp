#include "text_stream_old_format_database_saver_t.h"

#include <fstream>
#include <map>

text_stream_old_format_database_saver_t::text_stream_old_format_database_saver_t(std::string const &filename)
    : stream_old_format_database_saver_t(std::move(std::ofstream(filename)))
{
}

void text_stream_old_format_database_saver_t::save(database_t const &database)
{
    std::map<std::pair<team_t, team_t>, std::pair<size_t, size_t>> mapping;
    for (auto const &match : database.matches_get())
    {
        auto team_pair = std::make_pair(match.first(), match.second());
        std::pair<size_t, size_t> win_pair;

        auto it = mapping.find(team_pair);
        if(it == mapping.end())
        {
            mapping.insert({team_pair, {}});
        }
        
    }
}