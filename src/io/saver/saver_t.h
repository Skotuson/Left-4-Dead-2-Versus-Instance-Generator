#pragma once

template <typename T>
struct saver_t
{
    virtual void save(T item) = 0;
};