#pragma once

#include "stream_text_saver_t.h"

struct file_stream_text_saver_t : stream_text_saver_t
{
    file_stream_text_saver_t(std::string const & filename);

    void save(std::string const & str);
};