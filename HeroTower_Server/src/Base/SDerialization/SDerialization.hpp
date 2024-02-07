#ifndef SDERIALIZATION_HPP
#define SDERIALIZATION_HPP

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "../PlayerKeys/PlayerKeys.hpp"

template <typename T>
char *serialize(const T g, const char *header, int &packetLen)
{
    int headerLen = strlen(header) + 1;
    int dataLen = sizeof(T);
    packetLen = headerLen + dataLen;

    char *data = (char *)malloc(dataLen);
    char *packet = (char *)malloc(packetLen);

    std::memcpy(data, &g, sizeof(T));

    for (int i = 0; i < packetLen; i++)
    {
        if (i < headerLen)
        {
            packet[i] = header[i];
        }
        else
        {
            packet[i] = data[i - headerLen];
        }
    }

    free(data);

    return packet;
}

template <typename T>
void deserialize(char *packet, T &g)
{
    int headerLen = strlen(packet) + 1;
    int dataLen = sizeof(T);
    int packetLen = headerLen + dataLen;

    char *header = (char *)malloc(headerLen);
    char *data = (char *)malloc(dataLen);

    for (int i = 0; i < packetLen; i++)
    {
        if (i < headerLen)
        {
            header[i] = packet[i];
        }
        else
        {
            data[i - headerLen] = packet[i];
        }
    }

    std::memcpy(&g, data, dataLen);

    free(header);
    free(data);
}

#endif