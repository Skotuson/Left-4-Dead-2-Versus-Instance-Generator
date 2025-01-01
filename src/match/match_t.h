#pragma once

#include <chrono>

#include "../team/team_t.h"

struct match_t
{
    using timestamp_t = std::chrono::system_clock::time_point;

    match_t(team_t const &team_a, team_t const &team_b, bool outcome, timestamp_t const &timestamp = std::chrono::system_clock::now());

private:
    team_t const team_a_;
    team_t const team_b_;

    // 0 signals that team A won, 1 signals that team B won
    bool outcome_;

    std::chrono::system_clock::time_point timestamp_;
};