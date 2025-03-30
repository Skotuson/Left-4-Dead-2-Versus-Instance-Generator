#pragma once

#include "../param_handler_t.h"

struct list_games_handler_t :param_handler_t {
    list_games_handler_t(std::string const &flag, controller_t &controller);

    std::optional<std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>>> process(std::list<std::string> const &args) override;

    std::string help(void) const override;
};