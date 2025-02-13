#pragma once

#pragma once

#include <string>
#include <memory>
#include <vector>

#include "../../store/cmd/command_t.h"

struct controller_t
{
    void push_command(std::shared_ptr<command_t> cmd);
    std::vector<std::shared_ptr<command_t>> const &get_commands(void) const;

private:
    std::vector<std::shared_ptr<command_t>> commands_;
};
