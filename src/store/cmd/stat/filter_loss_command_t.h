#pragma once

#include "../command_t.h"

#include <string>

struct filter_loss_command_t : command_t
{
    filter_loss_command_t(std::string const & player);

    void execute(database_t &db) const;

private:
    std::string player_;
    size_t const PRINT_PRECISION_ = 4;
};