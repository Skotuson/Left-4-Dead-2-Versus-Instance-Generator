#pragma once

#include "../old_format_database_saver_t.h"

#include <ostream>
#include <memory>

struct stream_old_format_database_saver_t : old_format_database_saver_t
{
    stream_old_format_database_saver_t(std::unique_ptr<std::ostream> os)
        : underlying_(std::move(os))
    {
    }

protected:
    std::unique_ptr<std::ostream> underlying_;
};