#pragma once
#include <iostream>
#include <cassert>

class Letter
{
private:
    char letter;

public:
    Letter(char c)
        : letter(c)
    {
    }
    Letter() 
        : letter('\0')
    {
    }

    char getLetter() const { return letter; }
    void printLetter() const 
    { 
        // перевірка того, чи є щось у літері
        if (letter != '\0') 
            std::cout << letter; 
    }
};