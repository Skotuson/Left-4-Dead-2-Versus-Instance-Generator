#include "add_handler_t.h"

#include <memory>

add_handler_t::add_handler_t(std::string const &flag, controller_t &controller)
    : param_handler_t(flag, controller)
{
}

std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> add_handler_t::process(std::list<std::string> const &args)
{
    if (args.empty())
    {
        // TODO
        // return std::make_shared<error_handler_t<_PARAM_HANDLER_PAIR_>>(flag_, "No input file provided");
    }

    std::shared_ptr<command_t> cmd;

    controller_.push_command(cmd);
    return std::nullopt;
}

std::string add_handler_t::help(void) const
{
    // TODO:
    return "-a, --add";
}