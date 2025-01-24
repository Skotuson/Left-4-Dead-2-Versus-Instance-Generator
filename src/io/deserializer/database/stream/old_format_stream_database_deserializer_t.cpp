#include "old_format_stream_database_deserializer_t.h"

#include <regex>

database_t old_format_stream_database_deserializer_t::deserialize(std::istream &is) const
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

        if (std::regex_match(line, match, database_t::OLD_DB_FORMAT))
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
            size_t wins_a = std::stoi(match[3].str());
            size_t wins_b = std::stoi(match[4].str());

            auto register_matches = [&](team_t const &team_a, team_t const &team_b, match_t::outcome_t outcome, size_t n_games)
            {
                while (n_games--)
                {
                    db.match_add(match_t(team_a, team_b, outcome));
                }
            };

            register_matches(team_a, team_b, match_t::outcome_t::FIRST_TEAM_WON, wins_a);
            register_matches(team_a, team_b, match_t::outcome_t::SECOND_TEAM_WON, wins_b);
        }

        else
        {
            // TODO: add error handling
        }
    }

    return db;
}