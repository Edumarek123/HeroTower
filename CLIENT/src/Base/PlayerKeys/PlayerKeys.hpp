#ifndef PLAYERKEYS_HPP
#define PLAYERKEYS_HPP

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

    void copy(const PlayerKeys &k);
};

#endif