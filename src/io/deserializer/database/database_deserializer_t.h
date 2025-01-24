#pragma once

#include "../deserializer_t.h"
#include "../../../store/database_t.h"

template <typename U>
struct database_deserializer_t : deserializer_t<database_t, U>
{
};