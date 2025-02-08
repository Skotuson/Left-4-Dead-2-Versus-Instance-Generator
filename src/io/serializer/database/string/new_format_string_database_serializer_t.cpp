#include "new_format_string_database_serializer_t.h"

#include <sstream>
#include <chrono>

std::string new_format_string_database_serializer_t::serialize(database_t const &database) const
{
    std::ostringstream result("");

    auto outcome_to_string = [](match_t::outcome_t outcome)
    {
        return outcome == match_t::outcome_t::FIRST_TEAM_WON ? "F" : "S";
    };

    auto gamemode_to_string = [](match_t::gamemode_t gamemode)
    {
        return gamemode == match_t::gamemode_t::NORMAL ? "N" : "R";
    };

    auto score_diff_to_string = [](std::optional<match_t::delta_t> const &score_diff)
    {
        return score_diff ? score_diff.value() : -1;
    };

    for (auto const &match : database.matches_get())
    {
        result << match.first() << " x "
               << match.second() << " : "
               << outcome_to_string(match.outcome())
               << " '" << match.map() << "'"
               << " " << gamemode_to_string(match.gamemode())
               << " " << score_diff_to_string(match.score_diff())
               << " " << std::chrono::duration_cast<std::chrono::seconds>(match.timestamp().time_since_epoch()).count()
               << std::endl;
    }

    return result.str();
}