#pragma once

#include <regex>
#include <chrono>
#include <optional>
#include <unordered_map>

#include "../team/team_t.h"

struct match_t
{
    static inline std::regex const &OLD_MATCH_FORMAT = std::regex(R"((.+?)\s+x\s+(.+?)\s+-\s+(\d+)\s*:\s*(\d+))");
    static inline std::regex const &NEW_MATCH_FORMAT = std::regex(R"((.+?)\s+x\s+(.+?)\s+-\s+(S|F)\s+'(.*?)'\s+(N|R)\s+(-?\d+)\s+(\d+))");

    enum outcome_t
    {
        FIRST_TEAM_WON,
        SECOND_TEAM_WON
    };

    enum gamemode_t
    {
        NORMAL,
        REALISM
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

    static inline std::unordered_map<map_t, std::string> const MAP_TO_STRING = {
        {map_t::NO_MERCY, "No Mercy"},
        {map_t::CRASH_COURSE, "Crash Course"},
        {map_t::DEATH_TOLL, "Death Toll"},
        {map_t::DEAD_AIR, "Dead Air"},
        {map_t::BLOOD_HARVEST, "Blood Harvest"},
        {map_t::THE_SACRIFICE, "The Sacrifice"},
        {map_t::THE_LAST_STAND, "The Last Stand"},
        {map_t::DEAD_CENTER, "Dead Center"},
        {map_t::THE_PASSING, "The Passing"},
        {map_t::DARK_CARNIVAL, "Dark Carnival"},
        {map_t::SWAMP_FEVER, "Swamp Fever"},
        {map_t::HARD_RAIN, "Hard Rain"},
        {map_t::THE_PARISH, "The Parish"},
        {map_t::COLD_STREAM, "Cold Stream"},
        {map_t::NOT_APPLICABLE, "N/A"}};

    static inline std::unordered_map<std::string, map_t> const STRING_TO_MAP = {
        {"No Mercy", map_t::NO_MERCY},
        {"Crash Course", map_t::CRASH_COURSE},
        {"Death Toll", map_t::DEATH_TOLL},
        {"Dead Air", map_t::DEAD_AIR},
        {"Blood Harvest", map_t::BLOOD_HARVEST},
        {"The Sacrifice", map_t::THE_SACRIFICE},
        {"The Last Stand", map_t::THE_LAST_STAND},
        {"Dead Center", map_t::DEAD_CENTER},
        {"The Passing", map_t::THE_PASSING},
        {"Dark Carnival", map_t::DARK_CARNIVAL},
        {"Swamp Fever", map_t::SWAMP_FEVER},
        {"Hard Rain", map_t::HARD_RAIN},
        {"The Parish", map_t::THE_PARISH},
        {"Cold Stream", map_t::COLD_STREAM},
        {"N/A", map_t::NOT_APPLICABLE}};

    using delta_t = long long int;
    using timestamp_t = std::chrono::system_clock::time_point;

    match_t(team_t const &team_a, team_t const &team_b, outcome_t outcome,
            map_t map = NOT_APPLICABLE,
            gamemode_t const &gamemode = NORMAL,
            std::optional<delta_t> const &score_diff = {},
            timestamp_t const &timestamp = std::chrono::system_clock::time_point{});

    bool played(player_t const &player) const;
    bool won(player_t const &player) const;

    team_t const &first(void) const;
    team_t const &second(void) const;
    outcome_t const &outcome(void) const;
    map_t const &map(void) const;
    gamemode_t const &gamemode(void) const;
    std::optional<delta_t> const &score_diff(void) const;
    std::chrono::system_clock::time_point const &timestamp(void) const;

    friend std::ostream &operator<<(std::ostream &os, map_t const &map);

private:
    team_t const team_a_;
    team_t const team_b_;

    outcome_t outcome_;

    map_t map_;

    gamemode_t gamemode_;

    std::optional<delta_t> score_diff_;

    std::chrono::system_clock::time_point timestamp_;
};