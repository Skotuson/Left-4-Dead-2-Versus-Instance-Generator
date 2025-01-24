#pragma once

template <typename T, typename U>
struct deserializer_t
{
    virtual T deserialize(U item) const = 0;
}; // deserializer_t