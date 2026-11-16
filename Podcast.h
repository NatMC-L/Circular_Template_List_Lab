//
// Created by Christopher Vaughn on 10/24/25.
// downloaded on 11/16/25 by Natalia Meza 
// Working on the Podcast class to implement polymorphism with the Media base class.
//

#ifndef CIRCULARTEMPLATEDLIST_PODCAST_H
#define CIRCULARTEMPLATEDLIST_PODCAST_H

#include <iostream>
#include "Media.h"

// Represents a podcast episode, showing how multiple types can share the list.
class Podcast : public Media {
private:
    std::string episodeTitle;
    std::string host;
    int episodeNumber;
public:
    // Constructor
    Podcast(const std::string& t, const std::string& h, const int ep)
    : Media(t, 0), episodeTitle(t), host(h), episodeNumber(ep) {}

    // Override toString() from the Media base class.
    std::string toString() const override;

    // Override play() to provide Podcast-specific behavior.
    void play() const override;
};

#endif //CIRCULARTEMPLATEDLIST_PODCAST_H