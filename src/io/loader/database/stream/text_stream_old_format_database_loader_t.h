#pragma once

#include <string>

#include "stream_old_format_database_loader_t.h"

struct text_stream_old_format_database_loader_t : stream_old_format_database_loader_t
{
    text_stream_old_format_database_loader_t(std::string const &filename);
    database_t load() override;
};