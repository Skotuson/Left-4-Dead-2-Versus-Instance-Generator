#pragma once

#include <set>

#include "../player/player_t.h"

struct team_t
{
    void player_add(player_t const &player);

    using iterator_ = std::set<player_t>::iterator;
    using c_iterator_ = std::set<player_t>::const_iterator;

    iterator_ begin() { return teammates_.begin(); }
    iterator_ end() { return teammates_.end(); }

    c_iterator_ begin() const { return teammates_.begin(); }
    c_iterator_ end() const { return teammates_.end(); }

    c_iterator_ cbegin() const { return teammates_.cbegin(); }
    c_iterator_ cend() const { return teammates_.cend(); }

private:
    std::set<player_t> teammates_;
};