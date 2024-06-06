#include <iostream>
#include "operation.hpp"

// Залікова книжка: 3527
// 1 ( - ) 2 (2) 2 ( % ) 6 (double)


int main()
{
    int c2 = 3527 % 2, c3 = 3527 % 3, c5 = 3527 % 5, c7 = 3527 % 7;

    std::cout << c2 << " " << c3 << " " << c5 << " " << c7 << "\n";

    Operation C(10, 20); 

    std::cout << C.returnNumber(50, 100) << "\n";

    return 0;  
}