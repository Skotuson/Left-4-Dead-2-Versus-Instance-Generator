#pragma once

#include "stream_database_deserializer_t.h"

struct new_format_stream_database_deserializer_t : stream_database_deserializer_t
{
    database_t deserialize(std::istream &is) const;
}; // new_format_stream_database_deserializer_t