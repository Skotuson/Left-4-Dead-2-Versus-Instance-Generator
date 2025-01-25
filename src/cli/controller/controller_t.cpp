#include "controller_t.h"

void controller_t::push_command(std::shared_ptr<command_t> cmd)
{
    commands_.push(cmd);
}