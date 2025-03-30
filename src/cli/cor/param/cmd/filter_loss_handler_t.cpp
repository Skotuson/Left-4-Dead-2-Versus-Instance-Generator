#include "filter_loss_handler_t.h"

#include "../../../../store/cmd/stat/filter_loss_command_t.h"

filter_loss_handler_t::filter_loss_handler_t(std::string const &flag, controller_t &controller)
    : param_handler_t(flag, controller)
{
}

std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> filter_loss_handler_t::process(std::list<std::string> const &args)
{
    if (args.empty() || args.size() != 1)
    {
        // TODO: error handling
        throw "";
        // return std::make_shared<error_handler_t<_PARAM_HANDLER_PAIR_>>(flag_, "No input file provided");
    }
    controller_.push_command(std::make_shared<filter_loss_command_t>(args.front()));
    return std::nullopt;
}

std::string filter_loss_handler_t::help(void) const
{
    return "-fl, --filter-loss";
}