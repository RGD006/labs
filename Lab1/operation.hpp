#pragma once
#include <cassert>


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