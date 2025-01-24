#pragma once

#include "stream_database_deserializer_t.h"

struct old_format_stream_database_deserializer_t : stream_database_deserializer_t
{
    database_t deserialize(std::istream &is) const;
}; // old_format_stream_database_deserializer_t