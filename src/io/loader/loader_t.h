#pragma once

template <typename T>
struct loader_t
{
    virtual T load() = 0;
};