#include <iostream>
#include <cassert>

// Залікова книжка: 3527
// 1 ( - ) 2 (2) 2 ( % ) 6 (double)

class Operation
{
private:
    const int const_number;
    const int a;
    const int b; 
public:
    Operation(const int _a, const int _b);
    double returnNumber(const double n, const double m);
};

Operation::Operation(const int _a, const int _b)
    : const_number(3527 % 3), a(_a), b(_b)
{
}

double Operation::returnNumber(const double n, const double m)
{
    double result = 0;
    for (double i = a; i < n; i += 1)
    {
        for (double j = b; j < m; j += 1)
        {
            assert(i - const_number != 0 && "one of the operations is equal 0");
            result += static_cast<double>((static_cast<int>(i) % static_cast<int>(j))) / (i - const_number);
        }
    }
    return result;
}

int main()
{
    int c2 = 3527 % 2, c3 = 3527 % 3, c5 = 3527 % 5, c7 = 3527 % 7;

    std::cout << c2 << " " << c3 << " " << c5 << " " << c7 << "\n";

    Operation C(10, 20); 

    std::cout << C.returnNumber(50, 100) << "\n";

    return 0;  
}