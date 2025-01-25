#include "new_format_string_database_serializer_t.h"

#include <sstream>

std::string new_format_string_database_serializer_t::serialize(database_t const &database) const
{
    std::ostringstream result("");

    auto outcome_to_string = [](match_t::outcome_t outcome)
    {
        return outcome == match_t::outcome_t::FIRST_TEAM_WON ? "F" : "S";
    };

    for (auto const &match : database.matches_get())
    {
        result << match.first() << " x "
               << match.second() << " - "
               << outcome_to_string(match.outcome())
               << " '" << match.map() << "'"
               << " " << match.timestamp().time_since_epoch().count()
               << std::endl;
    }

    return result.str();
}