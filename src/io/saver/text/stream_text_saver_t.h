#pragma once

#include "text_saver_t.h"

#include <memory>
#include <ostream>

struct stream_text_saver_t : text_saver_t
{
    stream_text_saver_t(std::unique_ptr<std::ostream> os);

protected:
    void export_to_stream(std::string const &out);

private:
    std::unique_ptr<std::ostream> underlying_;
};