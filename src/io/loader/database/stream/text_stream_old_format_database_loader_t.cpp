#include "text_stream_old_format_database_loader_t.h"

#include <fstream>
#include <sstream>

text_stream_old_format_database_loader_t::text_stream_old_format_database_loader_t(std::string const &filename)
    : stream_old_format_database_loader_t(std::make_unique<std::ifstream>(filename))
{
}

database_t text_stream_old_format_database_loader_t::load()
{
    database_t db;
    std::string line;
    while (std::getline(*underlying_, line))
    {
        // Strip windows linefeed
        if (line.back() == '\r')
        {
            line.pop_back();
        }

        std::smatch match;

        if (std::regex_match(line, match, format_))
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
                    db.match_add(match_t(team_a, team_b, outcome, std::chrono::system_clock::time_point{}));
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