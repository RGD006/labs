#pragma once
#include "sentence.hpp"
#include "algorithm"

class SortWords
{
private:
    Sentence sentence;

public:
    SortWords(const Sentence &_sentence)
        : sentence(_sentence)
    {
    }

    void sortWords()
    {
        std::vector<Word> words;

        for (const auto &pair : sentence.getSentence())
        {
            if (pair.first.getSize() > 0)
                words.push_back(pair.first);
        }

        std::sort(words.begin(), words.end(), [](const Word &a, const Word &b)
                  { return a.getSize() < b.getSize(); });

        Letter space(' ');

        for (const auto &word : words)
        {
            word.printWord();
            space.printLetter();
        }
    }
};