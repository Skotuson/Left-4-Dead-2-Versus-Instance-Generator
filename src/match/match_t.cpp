#include "match_t.h"

match_t::match_t(team_t const &team_a, team_t const &team_b, bool victory, match_t::timestamp_t const &timestamp)
    : team_a_(team_a),
      team_b_(team_b),
      victory_(victory),
      timestamp_(timestamp)
{
}