#include "match_t.h"

#include <iomanip>

match_t::match_t(team_t const &team_a, team_t const &team_b,
                 match_t::outcome_t outcome,
                 match_t::map_t map,
                 std::optional<match_t::delta_t> const &score_diff,
                 match_t::timestamp_t const &timestamp)
    : team_a_(team_a),
      team_b_(team_b),
      outcome_(outcome),
      map_(map),
      score_diff_(score_diff),
      timestamp_(timestamp)
{
}

team_t const &match_t::first(void) const
{
  return team_a_;
}

team_t const &match_t::second(void) const
{
  return team_b_;
}

match_t::outcome_t const &match_t::outcome(void) const
{
  return outcome_;
}

match_t::map_t const &match_t::map(void) const
{
  return map_;
}

std::chrono::system_clock::time_point const &match_t::timestamp(void) const
{
  return timestamp_;
}

std::ostream &operator<<(std::ostream &os, match_t::map_t const &map)
{
  std::string name = "";
  switch (map)
  {
  case match_t::map_t::NO_MERCY:
    name = "No Mercy";
    break;
  case match_t::map_t::CRASH_COURSE:
    name = "Crash Course";
    break;
  case match_t::map_t::DEATH_TOLL:
    name = "Death Toll";
    break;
  case match_t::map_t::DEAD_AIR:
    name = "Dead Air";
    break;
  case match_t::map_t::BLOOD_HARVEST:
    name = "Blood Harvest";
    break;
  case match_t::map_t::THE_SACRIFICE:
    name = "The Sacrifice";
    break;
  case match_t::map_t::THE_LAST_STAND:
    name = "The Last STand";
    break;
  case match_t::map_t::DEAD_CENTER:
    name = "Dead Center";
    break;
  case match_t::map_t::THE_PASSING:
    name = "The Passing";
    break;
  case match_t::map_t::DARK_CARNIVAL:
    name = "Dark Carnival";
    break;
  case match_t::map_t::SWAMP_FEVER:
    name = "Swamp Fever";
    break;
  case match_t::map_t::HARD_RAIN:
    name = "Hard Rain";
    break;
  case match_t::map_t::THE_PARISH:
    name = "The Parish";
    break;
  case match_t::map_t::COLD_STREAM:
    name = "Cold Stream";
    break;
  case match_t::map_t::NOT_APPLICABLE:
    name = "N/A";
    break;
  }
  return os << std::quoted(name);
}