#pragma once

#include "../loader_t.h"
#include "../../store/database_t.h"

struct database_loader_t : loader_t<database_t>
{
    virtual database_t load() = 0;
};