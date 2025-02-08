#include "add_handler_t.h"

#include <memory>
#include <vector>
#include <sstream>
#include <numeric>

#include "../../../../io/deserializer/database/stream/new_format_stream_database_deserializer_t.h"
#include "../../../../store/cmd/mut/add_match_command_t.h"

add_handler_t::add_handler_t(std::string const &flag, controller_t &controller)
    : param_handler_t(flag, controller)
{
}

std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> add_handler_t::process(std::list<std::string> const &args)
{
    if (args.empty())
    {
        // TODO: error handling
        throw "";
        // return std::make_shared<error_handler_t<_PARAM_HANDLER_PAIR_>>(flag_, "No input file provided");
    }

    std::shared_ptr<new_format_stream_database_deserializer_t> deserializer(std::make_shared<new_format_stream_database_deserializer_t>());

    std::istringstream iss(
        std::accumulate(std::next(args.begin()), args.end(), args.front(),
                        [](std::string const &a, std::string const &b)
                        {
                            return a + " " + b;
                        }));

    controller_.push_command(std::make_shared<add_match_command_t>(
        deserializer->deserialize(iss).matches_get().front()));
    return std::nullopt;
}

std::string add_handler_t::help(void) const
{
    // TODO:
    return "-a, --add";
}