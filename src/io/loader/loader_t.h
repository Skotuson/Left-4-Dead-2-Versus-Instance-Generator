#pragma once

template <typename T>
struct loader_t
{
    virtual ~loader_t() = default;

    virtual T load() = 0;
};