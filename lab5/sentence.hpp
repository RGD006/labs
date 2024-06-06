#pragma once
#include "word.hpp"
#include "punctuation_mark.hpp"
#include <vector>
#include <cassert>

class Sentence
{
    // це для того, щоб зручніше було читати код
    using pair_Word_PunctionMark = std::pair<Word, PunctuationMark>; 

private:
    std::vector<pair_Word_PunctionMark> sentence;

public:
    Sentence() = default;
    Sentence(const Sentence &copy)
    {
        sentence = copy.getSentence();
    }

    void addWord(Word word)
    {
        sentence.push_back(std::make_pair(word, PunctuationMark()));
    }

    void addPunctionMark(PunctuationMark mark)
    {
        sentence.push_back(std::make_pair(Word(), mark));
    }

    std::vector<pair_Word_PunctionMark> getSentence() const { return sentence; }

    // в аргументі функції можна написати свій знак для розділу слів
    void printSentence(Letter delimiter = Letter(' ')) const
    {
        for (size_t i = 0; i < sentence.size(); i++)
        {
            if (sentence[i].second.getMark() == '\0')
                sentence[i].first.printWord();
            else if (sentence[i].second.getMark() != '\0')
                sentence[i].second.printMark();
            if (i != sentence.size() - 1)
                delimiter.printLetter();
        }
    }

    pair_Word_PunctionMark getWord(size_t index) const
    {
        assert(index > 0 && "index is below zero");

        return sentence[index];
    }
};