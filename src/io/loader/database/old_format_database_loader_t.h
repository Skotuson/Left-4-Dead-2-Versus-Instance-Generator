#pragma once

#include "database_loader_t.h"

#include <regex>

struct old_format_database_loader_t : database_loader_t
{
    old_format_database_loader_t(void)
        : database_loader_t(std::regex(R"((.+?)\s+x\s+(.+?)\s+-\s+(\d+)\s*:\s*(\d+))"))
    {
    }
};