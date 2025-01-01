#pragma once

#include "../loader_t.h"
#include "../../store/database_t.h"

#include <regex>

struct database_loader_t : loader_t<database_t>
{
    database_loader_t(std::regex const &format)
        : format_(format)
    {
    }

protected:
    std::regex format_;
};