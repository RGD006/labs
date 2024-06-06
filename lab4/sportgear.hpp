#pragma once
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>

enum sort
{
    growth = 1,
    decline = 0,
}; // цей enum для виду сортування

class Sportgear
{
private:
    std::string name;
    std::string market;
    double price;
    int32_t count;
    int32_t id;

public:
    Sportgear(const std::string &_name,
              const std::string &_market,
              const double &_price,
              const int32_t &_count,
              const int32_t &_id);
    Sportgear() = delete; // видалення "пустого" конструктура для того, щоб можна було писати тільки з аргументами
    std::string getName() { return name; } 
    std::string getMarket() { return market; }
    double getPrice() { return price; }
    int32_t getCount() { return count; }
    int32_t getId() { return id; }
    void print() const;
};

Sportgear::Sportgear(const std::string &_name,
                     const std::string &_market,
                     const double &_price,
                     const int32_t &_count,
                     const int32_t &_id)
    : name(_name), market(_market), price(_price), count(_count), id(_id)
{
}

void Sportgear::print() const
{
    std::cout << " | name: " << name
              << " | market: " << market
              << " | price: " << price
              << " | count: " << count
              << " | id: " << id << " |\n";
}

class Shop
{
private:
    std::vector<Sportgear> gear;

public:
    Shop(std::vector<Sportgear> _gear);
    Shop() = default;
    void addGear(const Sportgear &add);
    void sortGear(sort method);
    void printGear();
};

Shop::Shop(std::vector<Sportgear> _gear)
    : gear(std::move(_gear))
{
}

void Shop::addGear(const Sportgear &add)
{
    gear.push_back(add);
}

void Shop::sortGear(sort method = sort::growth)
{
    // зміна, в котрій зберігаєтся як саме буде відбуватися сортування
    auto function_compare = method ? [](Sportgear a, Sportgear b)
    { return a.getCount() < b.getCount(); }
                                   : [](Sportgear a, Sportgear b)
    { return a.getCount() > b.getCount(); };

    std::sort(begin(gear), end(gear), function_compare);
}

void Shop::printGear()
{
    for (const auto &element : gear)
        element.print();

    std::cout << "\n\n\n";
}