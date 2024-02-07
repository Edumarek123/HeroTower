#include "NetworkSerialization.hpp"

#include <iostream>
#include <cstring>

template <typename T>
char *serialize(T obj)
{
    char *packet = (char *)malloc(sizeof(obj));

    std::memcpy(packet, &obj, sizeof(&packet));

    return packet;
}

template <typename T>
T deserialize(const char *packet)
{
    T obj;
    T dest;
    std::memcpy(&obj, packet, sizeof(obj));
    dest.copy(obj);

    return dest;
}