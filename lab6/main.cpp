#include <iostream>
#include "album.hpp"
#include "rock.hpp"
#include "jazz.hpp"
#include "classic.hpp"

int32_t main()
{
    std::cout << "Variant: " << 3527 % 13 << std::endl; // 4

    Album mushroom;
    mushroom.addMusic(new Rock("Dude", "Aerosmith", 352));
    mushroom.addMusic(new Jazz("What a Wonderful World", "Lui Armstrong", 242));
    mushroom.addMusic(new Jazz("A kiss to Build a Dream on", "Lui Armstrong", 514));
    mushroom.addMusic(new Jazz("Fever", "Peggi Li", 413));
    mushroom.addMusic(new Rock("The Chain", "Fleetwood Mac", 600));
    mushroom.addMusic(new Classic("Tragic Overture", "Brahms", 210));
    mushroom.addMusic(new Rock("Take it Easy", "Eagles", 445));
    mushroom.addMusic( new Rock("Paranoid", "Black Sabbath", 152));
    mushroom.addMusic(new Rock("War Pig", "Black Sabbath", 643));

    mushroom.printAlbum();
    std::cout << "\n\n\n";
    mushroom.sortMusicsByStyle();
    mushroom.printAlbum();
    std::cout << "\n\n\n";

    Music* found = mushroom.findMusicByDuration(600);
    Music* not_find = mushroom.findMusicByDuration(700);

    std::cout << "find by duration 600: \n";

    if (found)
        found->printInfo();
    else
        std::cout << "Not Founded" << std::endl;

    std::cout << "\n\nFind by duration 700: \n";

    if (not_find)
        not_find->printInfo();
    else
        std::cout << "Not Founded" << std::endl;

    return 0;
};
