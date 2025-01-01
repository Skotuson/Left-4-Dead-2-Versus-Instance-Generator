#include "text_stream_old_format_database_saver_t.h"

#include <fstream>

text_stream_old_format_database_saver_t::text_stream_old_format_database_saver_t(std::string const &filename)
    : stream_old_format_database_saver_t(std::move(std::ofstream(filename)))
{
}

void text_stream_old_format_database_saver_t::save(database_t const &item)
{
    
}