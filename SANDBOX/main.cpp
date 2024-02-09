#include <cstring>
#include <cstdlib>
#include <iostream>

struct PlayerKeys
{
    bool _wIsPressed = false;
    bool _sIsPressed = false;
    bool _aIsPressed = false;
    bool _dIsPressed = false;
    bool _dashIsPressed = false;
    bool _n1IsPressed = false;
    bool _n2IsPressed = false;
    bool _n3IsPressed = false;
    bool _pauseIsPressed = false;
};

template <typename T>
char *serialize(const T g, const char *header)
{
    int headerLen = strlen(header) + 1;
    int dataLen = sizeof(T);
    int packetLen = headerLen + dataLen;

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

int main(void)
{

    PlayerKeys keys;
    keys._dIsPressed = true;

    char *packet = serialize(keys, "keyas");

    PlayerKeys p;

    std::cout << "w: " << p._wIsPressed << " a: " << p._aIsPressed << " d: " << p._dIsPressed << std::endl;
    deserialize(packet, p);
    std::cout << "w: " << p._wIsPressed << " a: " << p._aIsPressed << " d: " << p._dIsPressed << std::endl;

    free(packet);
}