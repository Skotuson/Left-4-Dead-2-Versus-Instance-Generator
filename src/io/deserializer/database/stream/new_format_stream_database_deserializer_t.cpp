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

        team_t team_a;
        team_t team_b;
        match_t::outcome_t outcome;
        match_t::map_t map = match_t::map_t::NOT_APPLICABLE;
        match_t::gamemode_t gamemode = match_t::gamemode_t::NORMAL;
        std::optional<match_t::delta_t> score_diff = std::nullopt;
        auto timestamp = std::chrono::system_clock::time_point{};

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

        // TODO: add some other method in the future
        if (std::regex_match(line, match, match_t::NEW_MATCH_FORMAT_FULL))
        {
            map = match_t::STRING_TO_MAP.at(match[4].str());
            gamemode = match[5].str() == "N" ? match_t::gamemode_t::NORMAL : match_t::gamemode_t::REALISM;
            score_diff = match[6].str() == "-1" ? std::nullopt : std::optional<match_t::delta_t>(std::stoll(match[6].str()));
            timestamp = std::chrono::system_clock::time_point(std::chrono::seconds(std::stoll(match[7].str())));
        }

        else if (std::regex_match(line, match, match_t::NEW_MATCH_FORMAT_NO_TIMESTAMP))
        {
            map = match_t::STRING_TO_MAP.at(match[4].str());
            gamemode = match[5].str() == "N" ? match_t::gamemode_t::NORMAL : match_t::gamemode_t::REALISM;
            score_diff = match[6].str() == "-1" ? std::nullopt : std::optional<match_t::delta_t>(std::stoll(match[6].str()));
        }

        else if (std::regex_match(line, match, match_t::NEW_MATCH_FORMAT_NO_SCORE_DIFF))
        {
            map = match_t::STRING_TO_MAP.at(match[4].str());
            gamemode = match[5].str() == "N" ? match_t::gamemode_t::NORMAL : match_t::gamemode_t::REALISM;
        }

        else if (std::regex_match(line, match, match_t::NEW_MATCH_FORMAT_NO_GAMEMODE))
        {
            map = match_t::STRING_TO_MAP.at(match[4].str());
        }

        else if (std::regex_match(line, match, match_t::NEW_MATCH_FORMAT_NO_MAP))
        {
        }

        else
        {
            // TODO: add error handling
            throw "";
        }

        team_a = collect_team(match[1].str());
        team_b = collect_team(match[2].str());
        outcome = match[3].str() == "F" ? match_t::outcome_t::FIRST_TEAM_WON : match_t::outcome_t::SECOND_TEAM_WON;

        db.match_add(match_t(team_a, team_b, outcome, map, gamemode, score_diff, timestamp));
    }

    return db;
}