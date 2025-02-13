#include "controller_t.h"

void controller_t::push_command(std::shared_ptr<command_t> cmd)
{
    commands_.emplace_back(cmd);
}

std::vector<std::shared_ptr<command_t>> const & controller_t::get_commands(void) const
{
    return commands_;
}