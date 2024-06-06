#pragma once
#include <iostream>
#include <cstdint>
#include <string>


class Music // умовний інтерфейс для класів Rock Jazz Classic
{
private:
    std::string title;
    std::string author;
    std::string style;
    int32_t duration;

public:
    Music(std::string _title, std::string _author, int32_t _duration)
        : title(std::move(_title)), author(std::move(_author)), duration(_duration)
    {
    }

    int32_t getDuration() const { return duration; }

    virtual std::string getStyle() const = 0;
    virtual void printInfo() const
    {
        std::cout << "| Title: " << title
                  << " | Author: " << author
                  << " | duration" << duration << std::endl;
    }

    Music() = delete;
};