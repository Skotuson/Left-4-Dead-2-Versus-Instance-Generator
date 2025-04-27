#include "filter_games_season_handler_t.hpp"

#include "../../../../store/cmd/stat/filter_games_season_command_t.hpp"

filter_games_season_handler_t::filter_games_season_handler_t(std::string const &flag, controller_t &controller)
    : param_handler_t(flag, controller)
{
}

std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> filter_games_season_handler_t::process(std::list<std::string> const &args)
{
    controller_.push_command(std::make_shared<filter_games_season_command_t>(args.front()));
    return std::nullopt;
}

std::string filter_games_season_handler_t::help(void) const
{
    return "-fgs, --filter-games-season";
}