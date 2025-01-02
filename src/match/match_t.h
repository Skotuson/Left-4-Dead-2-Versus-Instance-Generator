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

    using timestamp_t = std::chrono::system_clock::time_point;

    match_t(team_t const &team_a, team_t const &team_b, outcome_t outcome,
            timestamp_t const &timestamp = std::chrono::system_clock::now());

    team_t const & first(void) const;
    team_t const & second(void) const;
    outcome_t const & outcome(void) const;

private:
    team_t const team_a_;
    team_t const team_b_;

    outcome_t outcome_;

    std::chrono::system_clock::time_point timestamp_;
};