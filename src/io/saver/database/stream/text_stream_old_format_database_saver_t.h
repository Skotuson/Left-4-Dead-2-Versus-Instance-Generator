#pragma once

#include <string>

#include "stream_old_format_database_saver_t.h"

struct text_stream_old_format_database_saver_t : stream_old_format_database_saver_t
{
    text_stream_old_format_database_saver_t(std::string const &filename);
    void save(database_t const &item) override;
};