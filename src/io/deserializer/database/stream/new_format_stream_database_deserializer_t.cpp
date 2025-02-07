#include "new_format_stream_database_deserializer_t.h"

#include <regex>

database_t new_format_stream_database_deserializer_t::deserialize(std::istream &is) const
{
    database_t db;
    std::string line;
    while (std::getline(is, line))
    {
        // Strip windows linefeed
        if (line.back() == '\r')
        {
            line.pop_back();
        }

        std::smatch match;

        if (std::regex_match(line, match, match_t::NEW_MATCH_FORMAT))
        {
            auto collect_team = [&](std::string const &str)
            {
                team_t team;
                std::istringstream iss(str);
                player_t::player_id_t player_id;
                while (iss >> player_id)
                {
                    team.player_add(player_t(player_id));
                }

                db.team_add(team);
                return team;
            };

            auto team_a = collect_team(match[1].str());
            auto team_b = collect_team(match[2].str());
            auto outcome = match[3].str() == "F" ? match_t::outcome_t::FIRST_TEAM_WON : match_t::outcome_t::SECOND_TEAM_WON;
            auto map = match_t::STRING_TO_MAP.at(match[4].str());
            auto gamemode = match[5].str() == "N" ? match_t::gamemode_t::NORMAL : match_t::gamemode_t::REALISM;
            auto point_diff = match[6].str() == "-1" ? std::nullopt : std::optional<match_t::delta_t>(std::stoll(match[6].str()));
            auto timestamp = std::chrono::system_clock::time_point(std::chrono::seconds(std::stoll(match[7].str())));
            
            db.match_add(match_t(team_a, team_b, outcome, map, gamemode, point_diff, timestamp));
        }

        else
        {
            // TODO: add error handling
        }
    }

    return db;
}