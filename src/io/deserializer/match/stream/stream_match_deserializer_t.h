#pragma once

#include "../match_deserializer_t.h"

#include <istream>

struct stream_match_deserializer_t : match_deserializer_t<std::istream &>
{
};
