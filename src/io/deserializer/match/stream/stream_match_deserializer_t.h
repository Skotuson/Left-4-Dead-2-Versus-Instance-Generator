#pragma once

#include "../match_deserializer_t.h"

#include <istream>

struct match_database_deserializer_t : match_deserializer_t<std::istream &>
{
};
