#ifndef GPS_HPP
#define GPS_HPP

#include <iostream>
#include <sstream>
#include <string>

// include headers that implement a archive in simple text format
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

class GPS
{
public:
    int degrees;
    int minutes;
    float seconds;

    GPS()
    {
        degrees = 0;
        minutes = 0;
        seconds = 0;
    };
    GPS(int d, int m, float s) : degrees(d), minutes(m), seconds(s)
    {
    }

    void print()
    {
        std::cout << degrees << " " << minutes << " " << seconds << std::endl;
    }

    void save(char &data)
    {
        }

    void load(const char *data)
    {
    }
};

#endif