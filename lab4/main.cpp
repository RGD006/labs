#include <iostream>
#include "sportgear.hpp"

// variant 7

int32_t main()
{
    int32_t c11 = 3527 % 11;
    std::cout << "Variant: " << c11 << " sorting will be by <count> variable" << std::endl;

    Sportgear a("Sneakers", "Puma", 97.5, 10, 1), 
              b("T-shirt", "Adidas", 15.0, 2, 2),
              c("Ball for Basketball", "Company", 50.5, 1, 3),
              d("Gloves for boxing", "Everlast", 150.6, 50, 4),
              e("Climbing shoes", "Las Sportiva", 112.0, 4, 5);
    
    Shop shop;
    shop.addGear(a);
    shop.addGear(b);
    shop.addGear(c);
    shop.addGear(d);
    shop.addGear(e);

    shop.printGear();
    shop.sortGear();
    shop.printGear();
    shop.sortGear(sort::decline);
    shop.printGear();

    return 0;
}
