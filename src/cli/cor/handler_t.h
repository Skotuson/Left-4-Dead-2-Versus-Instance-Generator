#pragma once

#include <functional>
#include <iostream>
#include <optional>
#include <memory>

template <typename T>
struct handler_t
{
    virtual ~handler_t() = default;

    virtual std::optional<std::shared_ptr<handler_t<T>>> handle(T const &item) = 0;
    virtual std::shared_ptr<handler_t<T>> set_next(std::shared_ptr<handler_t<T>> const &next) = 0;

    static void resolve_all(std::shared_ptr<handler_t<T>> const &init_handler, T const &value)
    {
        std::function<void(std::shared_ptr<handler_t<T>> const &)> handler_loop = [&](std::shared_ptr<handler_t<T>> const &current_handler)
        {
            auto curr = current_handler->handle(value);
            if (curr)
            {
                handler_loop(curr.value());
            }
        };
        handler_loop(init_handler);
    }
};