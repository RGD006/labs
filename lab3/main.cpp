#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 3527 -> 2, 8

class StringSlicer
{
private:
    std::vector<std::pair<std::string, uint8_t>> texts;
    std::vector<std::pair<std::string, uint8_t>> split(std::string text, char delimeter);
public:
    StringSlicer(std::string text);
    void sortText();
    void printText();
};

std::vector<std::pair<std::string, uint8_t>> StringSlicer::split(std::string text, char delimeter)
{
    size_t start = 0;
    std::vector<std::pair<std::string, uint8_t>> tmp;
    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == delimeter)
        {
            std::string tmp_str = text.substr(start, i - start);
            tmp.push_back(std::make_pair(tmp_str, tmp_str.size()));
            start = ++i;
        }
    }

    if (!text.empty())
        tmp.push_back(std::make_pair(text.substr(start, text.size() - start), text.size() - start)); 

    return tmp;    
}

StringSlicer::StringSlicer(std::string text)
{
    texts = split(text, ' ');
}

void StringSlicer::sortText()
{
    std::sort(begin(texts), end(texts),
              [](std::pair<std::string, uint8_t> a, std::pair<std::string, uint8_t> b)
              { return a.second < b.second ;});
}

void StringSlicer::printText()
{
    for (const auto text : texts)
        std::cout << text.first << " ";
    std::cout << std::endl; 
}

int main()
{
    int c3 = 3527 % 3, c17 = 3527 % 17;
    std::cout << c3 << " " << c17 << "\n";

    std::string text;
    std::cout << "Enter text:\n";
    std::getline(std::cin, text);

    StringSlicer C(text);
    C.printText();
    C.sortText();
    C.printText();

    return EXIT_SUCCESS;
}