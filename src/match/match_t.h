#pragma once

#include <chrono>

#include "../team/team_t.h"

struct match_t
{
    enum outcome_t
    {
        FIRST_TEAM_WON,
        SECOND_TEAM_WON
    };

    enum map_t
    {
        NO_MERCY,
        CRASH_COURSE,
        DEATH_TOLL,
        DEAD_AIR,
        BLOOD_HARVEST,
        THE_SACRIFICE,
        THE_LAST_STAND,
        //
        DEAD_CENTER,
        THE_PASSING,
        DARK_CARNIVAL,
        SWAMP_FEVER,
        HARD_RAIN,
        THE_PARISH,
        COLD_STREAM,
        //
        NOT_APPLICABLE
    };

    using timestamp_t = std::chrono::system_clock::time_point;

    match_t(team_t const &team_a, team_t const &team_b, outcome_t outcome, 
            map_t map = NOT_APPLICABLE,
            timestamp_t const &timestamp = std::chrono::system_clock::time_point{});

    team_t const &first(void) const;
    team_t const &second(void) const;
    outcome_t const &outcome(void) const;
    map_t const & map(void) const;

private:
    team_t const team_a_;
    team_t const team_b_;

    outcome_t outcome_;

    map_t map_;

    std::chrono::system_clock::time_point timestamp_;
};