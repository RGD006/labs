#include <iostream>
#include "StringSlicer.hpp"

// 3527 -> 2, 8


int main()
{
    int c3 = 3527 % 3, c17 = 3527 % 17;
    std::cout << c3 << " " << c17 << "\n";

    std::string text;
    std::cout << "Enter text:\n";
    /*
    отримання всього тексту з врахування пробілів (треба натиснути Enter щоб закінчити рядок)
    */
    std::getline(std::cin, text); 

    StringSlicer C(text);
    C.sortText();
    std::cout << "Sorted text: ";
    C.printText();

    return EXIT_SUCCESS;
}