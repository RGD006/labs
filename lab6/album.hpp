#pragma once
#include "music.hpp"
#include <vector>
#include <algorithm>

class Album
{
private:
    /*
        для поліморфізму у с++ треба зберігати вказівник на клас інтерфейсу
    */
    std::vector<Music *> musics; 

public:
    Album() = default;

    void addMusic(Music *music)
    {
        musics.push_back(music);
    }

    void sortMusicsByStyle()
    {
        auto function_compare = [](Music *a, Music *b)
        { return a->getStyle() < b->getStyle(); };
        std::sort(begin(musics), end(musics), function_compare);
    }

    Music *findMusicByDuration(int32_t duration)
    {
        for (const auto &music : musics)
        {
            if (music->getDuration() == duration)
                return music;
        }

        return nullptr;
    }

    void printAlbum()
    {
        for (const auto &music : musics)
            music->printInfo();
    }

    ~Album()
    {
        for (auto music : musics)
            delete music;
    }
};