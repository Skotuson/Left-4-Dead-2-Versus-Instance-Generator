#pragma once

#pragma once

#include <string>
#include <memory>
#include <queue>

#include "../../store/cmd/command_t.h"

struct controller_t
{
    void push_command(std::shared_ptr<command_t> cmd);
private:
    std::queue<std::shared_ptr<command_t>> commands_;
};
