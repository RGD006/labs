#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class StringSlicer
{
private:
    std::vector<std::pair<std::string, uint8_t>> texts; // Зберігає масив слів з їх розміром
    std::vector<std::pair<std::string, uint8_t>> split(std::string text, char delimeter);

public:
    StringSlicer(std::string text);
    void sortText();
    void printText();
};


// функція, котра ділить рядок на масив зі словами та розміром слова
std::vector<std::pair<std::string, uint8_t>> StringSlicer::split(std::string text, char delimeter)
{
    std::vector<std::pair<std::string, uint8_t>> tmp;
    std::stringstream ss(text); // c++ StringBuilder
    std::string str_tmp;
    while (std::getline(ss, str_tmp, delimeter))
        tmp.push_back(std::make_pair(str_tmp, str_tmp.size()));

    return tmp;
}

StringSlicer::StringSlicer(std::string text)
{
    texts = split(text, ' ');
}

void StringSlicer::sortText()
{
    // сортування через лямбда-функцію
    std::sort(begin(texts), end(texts),
              [](std::pair<std::string, uint8_t> a, std::pair<std::string, uint8_t> b)
              { return a.second < b.second; }); 
}

void StringSlicer::printText()
{
    for (const auto text : texts)
        std::cout << text.first << " ";
    std::cout << std::endl;
}