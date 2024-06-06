#pragma once
#include "music.hpp"

class Jazz : public Music
{
public:
    Jazz(std::string _title, std::string _author, int32_t _duration)
        : Music(std::move(_title), std::move(_author), _duration)
    {
    }

    std::string getStyle() const override { return "Jazz"; }
    void printInfo() const override
    {
        std::cout << "Jazz: \n";
        Music::printInfo();
    }
};