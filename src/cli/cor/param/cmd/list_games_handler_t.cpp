#include "list_games_handler_t.h"

#include "../../../../store/cmd/stat/list_games_command_t.h"

list_games_handler_t::list_games_handler_t(std::string const &flag, controller_t &controller)
    : param_handler_t(flag, controller)
{
}

std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> list_games_handler_t::process(std::list<std::string> const &args)
{
    controller_.push_command(std::make_shared<list_games_command_t>());
    return std::nullopt;
}

std::string list_games_handler_t::help(void) const
{
    return "-lg, --list-games";
}