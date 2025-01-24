#pragma once

#include "../database_deserializer_t.h"

#include <istream>

struct stream_database_deserializer_t : database_deserializer_t<std::istream &>
{
};
