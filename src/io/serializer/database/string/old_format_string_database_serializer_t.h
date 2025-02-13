#pragma once

#include "string_database_serializer_t.h"

struct old_format_string_database_serializer_t : string_database_serializer_t
{
    std::string serialize(database_t const &database) const;
};