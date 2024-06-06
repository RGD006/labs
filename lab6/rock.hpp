#pragma once
#include "music.hpp"

class Rock : public Music
{
public:
    Rock(std::string _title, std::string _author, int32_t _duration)
        : Music(std::move(_title), std::move(_author), _duration)
    {
    }

    std::string getStyle() const override { return "Rock"; }
    void printInfo() const override
    {
        std::cout << "Rock: \n";
        Music::printInfo();
    }
};

