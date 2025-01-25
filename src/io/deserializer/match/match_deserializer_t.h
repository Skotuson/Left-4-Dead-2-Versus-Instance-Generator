#pragma once

#include "../deserializer_t.h"
#include "../../../match/match_t.h"

template <typename U>
struct match_deserializer_t : deserializer_t<match_t, U>
{
};