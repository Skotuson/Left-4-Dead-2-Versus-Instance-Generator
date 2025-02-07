#include "match_t.h"

#include <iomanip>

match_t::match_t(team_t const &team_a, team_t const &team_b,
                 match_t::outcome_t outcome,
                 match_t::map_t map,
                 match_t::gamemode_t const &gamemode,
                 std::optional<match_t::delta_t> const &score_diff,
                 match_t::timestamp_t const &timestamp)
    : team_a_(team_a),
      team_b_(team_b),
      outcome_(outcome),
      map_(map),
      gamemode_(gamemode),
      score_diff_(score_diff),
      timestamp_(timestamp)
{
}

bool match_t::played(player_t const &player) const
{
  return first().player_get(player.identifier()) || second().player_get(player.identifier());
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

match_t::gamemode_t const &match_t::gamemode(void) const
{
  return gamemode_;
}

std::optional<match_t::delta_t> const &match_t::score_diff(void) const 
{
  return score_diff_;
}

std::chrono::system_clock::time_point const &match_t::timestamp(void) const
{
  return timestamp_;
}

std::ostream &operator<<(std::ostream &os, match_t::map_t const &map)
{
  return os << match_t::MAP_TO_STRING.at(map);
}