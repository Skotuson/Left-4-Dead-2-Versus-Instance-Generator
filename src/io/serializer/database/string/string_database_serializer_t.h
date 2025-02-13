#pragma once

#include "../database_serializer_t.h"

#include <string>

struct string_database_serializer_t : database_serializer_t<std::string>
{
};