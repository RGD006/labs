#pragma once
#include <vector>
#include "letter.hpp"

class Word
{
private:
    std::vector<Letter> letters;
    size_t size;

public:
    Word(std::vector<Letter> _letters)
        : letters(_letters), size(_letters.size())
    {
    }

    Word()
        : size(0)
    {
    }

    void addLetter(const Letter &c)
    {
        letters.push_back(c);
        size++;
    }

    size_t getSize() const { return size; }

    void printWord() const
    {
        for (const auto &c : letters)
            c.printLetter();
    }
};