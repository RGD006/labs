#pragma once
#include <iostream>

class PunctuationMark
{
private:
    char mark;

public:
    PunctuationMark(char _mark)
        : mark(_mark)
    { 
    }
    PunctuationMark()
        : mark('\0')
    {
    }

    char getMark() const { return mark; }
    void printMark() const 
    { 
        if (mark != '\0')
            std::cout << mark; 
    }
};