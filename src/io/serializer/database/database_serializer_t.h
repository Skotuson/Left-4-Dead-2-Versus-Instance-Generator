#pragma once

#include "../serializer_t.h"
#include "../../../store/database_t.h"

template <typename U>
struct database_serializer_t : serializer_t<database_t const &, U>
{
};