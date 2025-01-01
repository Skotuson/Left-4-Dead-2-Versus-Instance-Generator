#pragma once

#include "../old_format_database_loader_t.h"

#include <istream>

struct stream_old_format_database_loader_t : old_format_database_loader_t
{
    stream_old_format_database_loader_t(std::istream &&is)
        : underlying_(is)
    {
    }

protected:
    std::istream &underlying_;
};