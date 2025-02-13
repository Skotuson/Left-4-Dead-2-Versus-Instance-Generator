#pragma once

#include "handler_t.h"

template <typename T>
struct basic_handler_t : handler_t<T>
{
    virtual ~basic_handler_t(void) = default;

    std::optional<std::shared_ptr<handler_t<T>>> handle(T const &item) override
    {
        return next_handler_;
    }

    std::shared_ptr<handler_t<T>> set_next(std::shared_ptr<handler_t<T>> const &next) override
    {
        next_handler_ = next;
        if (next_handler_)
        {
            return next_handler_.value();
        }
        return nullptr;
    }

protected:
    std::optional<std::shared_ptr<handler_t<T>>> next_handler_;
};