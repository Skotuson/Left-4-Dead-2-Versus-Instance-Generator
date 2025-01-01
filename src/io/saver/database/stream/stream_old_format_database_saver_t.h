#pragma once

#include "../old_format_database_saver_t.h"

#include <ostream>

struct stream_old_format_database_saver_t : old_format_database_saver_t
{
    stream_old_format_database_saver_t(std::ostream &&os)
        : underlying_(os)
    {
    }

protected:
    std::ostream &underlying_;
};