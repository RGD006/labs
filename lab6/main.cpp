#include <iostream>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>




class Music
{
private:
    std::string title;
    std::string author;
    std::string style;
    int32_t duration;
public:
    Music(std::string  _title, std::string  _author, int32_t _duration)
        : title(std::move(_title)), author(std::move(_author)), duration(_duration)
    {
    }

    int32_t getDuration() const { return duration; }

    virtual std::string getStyle() const = 0;
    virtual void printInfo() const
    {
        std::cout << "| Title: " << title
                  << " | Author: " << author
                  << " | duration" << duration << std::endl;
    }

    Music() = delete;
};

class Rock : public Music
{
public:
    Rock(std::string  _title, std::string  _author, int32_t _duration)
        : Music(std::move(_title), std::move(_author), _duration)
    {
    }

    std::string getStyle() const override { return "Rock"; }
    void printInfo() const override
    {
        std::cout << "Rock: \n";
        Music::printInfo();
    }
};

class Classic : public Music
{
public:
    Classic(std::string  _title, std::string  _author, int32_t _duration)
            : Music(std::move(_title), std::move(_author), _duration)
    {
    }

    std::string getStyle() const override { return "Classic"; }
    void printInfo() const override
    {
        std::cout << "Classic: \n";
        Music::printInfo();
    }
};

class Jazz : public Music
{
public:
    Jazz(std::string  _title, std::string  _author, int32_t _duration)
        : Music(std::move(_title), std::move(_author), _duration)
    {
    }

    std::string getStyle() const override { return "Jazz"; }
    void printInfo() const override
    {
        std::cout << "Jazz: \n";
        Music::printInfo();
    }
};

class Album
{
private:
    std::vector<Music*> musics;
public:
    Album() = default;

    void addMusic(Music* music)
    {
        musics.push_back(music);
    }

    void sortMusicsByStyle()
    {
        auto function_compare = [](Music* a, Music* b) { return a->getStyle() < b->getStyle(); };
        std::sort(begin(musics), end(musics), function_compare);
    }

    Music* findMusicByDuration(int32_t duration)
    {
        for (const auto& music : musics)
        {
            if (music->getDuration() == duration)
                return music;
        }

        return nullptr;
    }

    void printAlbum()
    {
        for (const auto& music : musics)
            music->printInfo();
    }

    ~Album()
    {
        for (auto music : musics)
            delete music;
    }
};

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
