#include "arg_parser_t.h"

#include "../utility/list_utility.h"
#include "cor/param/cmd/add_handler_t.h"
#include "cor/param/cmd/winrate_handler_t.h"
#include "cor/param/cmd/list_games_handler_t.h"
#include "cor/param/cmd/filter_loss_handler_t.h"
#include "cor/param/cmd/list_seasons_handler_t.h"
#include "cor/param/cmd/filter_games_season_handler_t.hpp"

#include <memory>
#include <cassert>
#include <iostream>

arg_parser_t::arg_parser_t(controller_t &controller)
    : controller_(controller)
{
}

void arg_parser_t::parse(std::list<std::string> const &args)
{
    if (!args.empty() && args.front().front() == '-')
    {
        auto split = split_head_tail(args);
        auto [head, tail] = split.value();
        std::string flag = head;
        auto [rest, params] = yield_params(tail, {});
        handler_t<_PARAM_HANDLER_PAIR_>::resolve_all(get_chain(), {flag, params});
        parse(rest);
    }
}

std::pair<std::list<std::string>, std::list<std::string>> arg_parser_t::yield_params(std::list<std::string> const &args, std::list<std::string> const &acc)
{
    if (args.empty() || args.front().front() == '-')
    {
        return {args, acc};
    }

    auto split = split_head_tail(args);

    assert(split);

    auto [head, tail] = split.value();
    std::list<std::string> acc_cpy = acc;
    acc_cpy.emplace_back(head);
    return yield_params(tail, acc_cpy);
}

std::shared_ptr<handler_t<_PARAM_HANDLER_PAIR_>> arg_parser_t::get_chain(void)
{
    std::shared_ptr<param_handler_t> w_handler = std::make_shared<winrate_handler_t>("-w", controller_);
    std::shared_ptr<param_handler_t> winrate_handler = std::make_shared<winrate_handler_t>("--winrate", controller_);
    std::shared_ptr<param_handler_t> a_handler = std::make_shared<add_handler_t>("-a", controller_);
    std::shared_ptr<param_handler_t> add_handler = std::make_shared<add_handler_t>("--add", controller_);
    std::shared_ptr<param_handler_t> fl_handler = std::make_shared<filter_loss_handler_t>("-fl", controller_);
    std::shared_ptr<param_handler_t> filter_loss_handler = std::make_shared<filter_loss_handler_t>("--filter-loss", controller_);
    std::shared_ptr<param_handler_t> lg_handler = std::make_shared<list_games_handler_t>("-lg", controller_);
    std::shared_ptr<param_handler_t> list_games_handler = std::make_shared<list_games_handler_t>("--list-games", controller_);
    std::shared_ptr<param_handler_t> ls_handler = std::make_shared<list_seasons_handler_t>("-ls", controller_);
    std::shared_ptr<param_handler_t> list_seasons_handler = std::make_shared<list_seasons_handler_t>("--list-seasons", controller_);
    std::shared_ptr<param_handler_t> fgs_handler = std::make_shared<filter_games_season_handler_t>("-fgs", controller_);
    std::shared_ptr<param_handler_t> filter_games_seasons_handler = std::make_shared<filter_games_season_handler_t>("--filter-games-seasons", controller_);

    w_handler
        ->set_next(winrate_handler)
        ->set_next(a_handler)
        ->set_next(add_handler)
        ->set_next(fl_handler)
        ->set_next(filter_loss_handler)
        ->set_next(lg_handler)
        ->set_next(list_games_handler)
        ->set_next(ls_handler)
        ->set_next(list_seasons_handler)
        ->set_next(fgs_handler)
        ->set_next(filter_games_seasons_handler)
        ;

    return w_handler;
}