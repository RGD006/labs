#pragma once
#include "sentence.hpp"

class Text
{
private:
    std::vector<Sentence> sentences;

public:
    Text() = default;
    void addSentence(const Sentence &sentence)
    {
        sentences.push_back(sentence);
    }
    void printText() const
    {
        Word end_delimiter(std::vector<Letter>{Letter('.'), Letter(' ')});

        for (const auto &sentence : sentences)
        {
            sentence.printSentence();
            end_delimiter.printWord();
        }
    }
};