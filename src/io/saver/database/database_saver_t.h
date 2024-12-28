#pragma once

#include "../saver_t.h"
#include "../../store/database_t.h"

struct database_saver_t : saver_t<database_t const &>
{
};