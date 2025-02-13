#pragma once

#include "cor/param/param_handler_t.h"
#include "controller/controller_t.h"

#include <string>
#include <list>

struct arg_parser_t
{
    arg_parser_t(controller_t &controller);
    void parse(std::list<std::string> const &args);

private:
    std::pair<std::list<std::string>, std::list<std::string>> yield_params(std::list<std::string> const &args, std::list<std::string> const &acc);

    std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>> get_chain(void);

    controller_t &controller_;
};