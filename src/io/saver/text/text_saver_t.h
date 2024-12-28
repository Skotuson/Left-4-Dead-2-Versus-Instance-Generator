#pragma once

#include "../saver_t.h"

#include <string>

struct text_saver_t : saver_t<std::string const &>
{
    virtual void save(std::string const &item) = 0;
};