#include "match_t.h"

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