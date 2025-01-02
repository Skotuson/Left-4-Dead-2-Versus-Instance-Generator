#pragma once

#include "../old_format_database_loader_t.h"

#include <istream>
#include <memory>

struct stream_old_format_database_loader_t : old_format_database_loader_t
{
    stream_old_format_database_loader_t(std::unique_ptr<std::istream> is)
        : underlying_(std::move(is))
    {
    }

    virtual ~stream_old_format_database_loader_t() = default;

protected:
    std::unique_ptr<std::istream> underlying_;
};