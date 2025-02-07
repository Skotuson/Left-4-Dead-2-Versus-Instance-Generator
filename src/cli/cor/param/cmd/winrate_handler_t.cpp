#include "winrate_handler_t.h"

#include "../../../../store/cmd/stat/winrate_command_t.h"

winrate_handler_t::winrate_handler_t(std::string const &flag, controller_t &controller)
    : param_handler_t(flag, controller)
{
}

std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> winrate_handler_t::process(std::list<std::string> const &args)
{
    controller_.push_command(std::make_shared<winrate_command_t>());
    return std::nullopt;
}

std::string winrate_handler_t::help(void) const
{
    return "-w, --winrate";
}