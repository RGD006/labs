#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cassert>
#include <algorithm>

class Letter
{
private:
    char letter;
public:
    Letter(char c)
        : letter(c)
    {
    }
    Letter() = default;

    char getLetter() const { return letter; }
    void printLetter() const { std::cout << letter; }
};

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

    void addLetter(const Letter& c)
    {
        letters.push_back(c);
        size++;
    }

    size_t getSize() const { return size; }

    void printWord() const
    {
        for (const auto& c : letters)
            std::cout << c.getLetter();
    }
};

class PunctuationMark
{
private:
    char mark;
    size_t size = 1;
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
    void printMark() const { std::cout << mark; }
    size_t getSize() const { return size; }
};

class Sentence
{
    using pair_Word_PunctionMark = std::pair<Word, PunctuationMark>;

private:
    std::vector<pair_Word_PunctionMark> sentence;
public:
    Sentence() = default;
    Sentence(const Sentence& copy)
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

    void printSentence(Letter delimiter = Letter(' ')) const
    {
        for (size_t i = 0; i < sentence.size(); i++)
        {
            if (sentence[i].first.getSize() > 0 && sentence[i].second.getMark() == '\0')
                sentence[i].first.printWord();
            else if (sentence[i].first.getSize() == 0 && sentence[i].second.getMark() != '\0')
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

class Text
{
private:
    std::vector<Sentence> sentences;

public:
    Text() = default;
    void addSentence(const Sentence& sentence)
    {
        sentences.push_back(sentence);
    }
    void printText() const
    {
        Word end_delimiter(std::vector<Letter>{Letter('.'), Letter(' ')});

        for (const auto& sentence : sentences)
        {
            sentence.printSentence();
            end_delimiter.printWord();
        }
    }
};

// task from 3 lab: Відсортувати слова заданого тексту за зростанням кількості в них заданої літери.

class SortWords
{
private:
    Sentence sentence;
public:
    SortWords(const Sentence& _sentence)
        : sentence(_sentence)
    {
    }

    void sortWords()
    {
        std::vector<Word> words;

        for (const auto& pair : sentence.getSentence())
        {
            if (pair.first.getSize() > 0)
                words.push_back(pair.first);
        }

        std::sort(words.begin(), words.end(), [](const Word& a, const Word& b) {
            return a.getSize() < b.getSize();
        });

        Letter space(' ');

        for (const auto& word : words)
        {
            word.printWord();
            space.printLetter();
        }
    }
};

int32_t main()
{
    Letter h('h'), e('e'), l('l'), o('o'), m('m'), y('y'), n('n'), a('a'), v('V'), d('d'),
           i('i'), s('s'), new_row('\n');

    Word word_1;
    word_1.addLetter(h);
    word_1.addLetter(e);
    word_1.addLetter(l);
    word_1.addLetter(l);
    word_1.addLetter(o);

    word_1.printWord();
    new_row.printLetter();

    Word word_2;
    word_2.addLetter(m);
    word_2.addLetter(y);

    word_2.printWord();
    new_row.printLetter();

    Word word_3;
    word_3.addLetter(n);
    word_3.addLetter(a);
    word_3.addLetter(m); 
    word_3.addLetter(e);

    word_3.printWord();
    new_row.printLetter();

    PunctuationMark punctuation_mark('-');

    Word word_4;
    word_4.addLetter(i);
    word_4.addLetter(s);

    word_4.printWord();
    new_row.printLetter();

    Word word_5;
    word_5.addLetter(v);
    word_5.addLetter(l);
    word_5.addLetter(a);
    word_5.addLetter(d);

    word_5.printWord();
    new_row.printLetter();

    Sentence sentence_1;
    sentence_1.addWord(word_1);
    
    sentence_1.printSentence();
    new_row.printLetter();

    Sentence sentence_2;
    sentence_2.addWord(word_2);
    sentence_2.addWord(word_3);
    sentence_2.addWord(word_4);
    sentence_2.addPunctionMark(punctuation_mark);
    sentence_2.addWord(word_5);

    sentence_2.printSentence();
    new_row.printLetter();

    Text text;
    text.addSentence(sentence_1);
    text.addSentence(sentence_2);

    text.printText();
    new_row.printLetter();

    SortWords sort(sentence_2);
    sort.sortWords();

    return 0;
}