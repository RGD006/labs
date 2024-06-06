#pragma once
#include "music.hpp"

class Classic : public Music
{
public:
    Classic(std::string _title, std::string _author, int32_t _duration)
        : Music(std::move(_title), std::move(_author), _duration)
    {
    }

    std::string getStyle() const override { return "Classic"; }
    void printInfo() const override
    {
        std::cout << "Classic: \n";
        Music::printInfo();
    }
};