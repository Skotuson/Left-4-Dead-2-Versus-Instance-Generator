#pragma once

#include <list>
#include <tuple>
#include <string>
#include <optional>
#include <iostream>

#include "../basic_handler_t.h"
#include "../../controller/controller_t.h"

using _PARAM_HANDLER_PAIR_ = std::pair<std::string, std::list<std::string>>;

struct param_handler_t : basic_handler_t<_PARAM_HANDLER_PAIR_>
{
    param_handler_t(std::string const &flag, controller_t &controller)
        : controller_(controller),
          flag_(flag)
    {
    }

    std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> handle(_PARAM_HANDLER_PAIR_ const &param) override
    {
        if (param.first == flag_)
        {
            return process(param.second);
        }

        return std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>>(next_handler_);
    }

    virtual std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> process(std::list<std::string> const &args) = 0;

    virtual std::string help(void) const = 0;

protected:
    controller_t &controller_;

private:
    std::string const flag_;
};