#pragma once

template <typename T, typename U>
struct serializer_t
{
    virtual U serialize(T const &item) const = 0;
}; // serializer_t