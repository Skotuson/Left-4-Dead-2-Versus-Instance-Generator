#include "stream_text_saver_t.h"

stream_text_saver_t::stream_text_saver_t(std::unique_ptr<std::ostream> os)
    : underlying_(std::move(os))
{
}

void stream_text_saver_t::export_to_stream(std::string const &out)
{
    *underlying_ << out;
    underlying_->flush();
}