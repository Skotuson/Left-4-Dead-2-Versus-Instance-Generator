#pragma once

#include <list>
#include <string>
#include <optional>

template <typename T>
std::optional<std::pair<T, std::list<T>>> split_head_tail(std::list<T> const &list)
{
    if (list.empty())
    {
        return std::nullopt;
    }

    std::list<T> cpy = list;
    T head = cpy.front();
    cpy.pop_front();
    std::list<T> tail = cpy;
    return std::optional<std::pair<T, std::list<T>>>({head, tail});
}