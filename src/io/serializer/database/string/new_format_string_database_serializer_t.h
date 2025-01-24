#pragma once

#include "string_database_serializer_t.h"

struct new_format_string_database_serializer_t : string_database_serializer_t
{
    virtual std::string serialize(database_t const &item) const = 0;
};