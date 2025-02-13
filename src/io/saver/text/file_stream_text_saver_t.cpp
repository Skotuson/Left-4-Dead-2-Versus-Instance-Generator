#include "file_stream_text_saver_t.h"

#include <fstream>

file_stream_text_saver_t::file_stream_text_saver_t(std::string const &filename)
    : stream_text_saver_t(std::make_unique<std::ofstream>(filename))
{
}

void file_stream_text_saver_t::save(std::string const &str)
{
    export_to_stream(str);
}