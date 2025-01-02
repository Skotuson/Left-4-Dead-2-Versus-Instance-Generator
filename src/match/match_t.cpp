#include "match_t.h"

match_t::match_t(team_t const &team_a, team_t const &team_b, match_t::outcome_t outcome, match_t::timestamp_t const &timestamp)
    : team_a_(team_a),
      team_b_(team_b),
      outcome_(outcome),
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