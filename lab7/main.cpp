#include <iostream>
#include <cstdint>
#include <set>

class ICollection
{
public:

};

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





int32_t main()
{
    std::cout << "c2: " << 3527 % 2 << " c3: " << 3527 % 3 << std::endl; // 1 (Set), 2 (Двозв’язний список)

    return 0;
}
