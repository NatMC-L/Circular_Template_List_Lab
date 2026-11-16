//
// Created by Christopher Vaughn on 10/24/25.
// downloaded on 11/16/25 by Natalia Meza 
//

#include "Podcast.h"
#include <sstream>
// Override toString() from the Media base class.
std::string Podcast::toString() const{
    std::stringstream ss;
    ss << "Podcast: " << episodeTitle
       << " | Host: " << host
       << " | Ep #: " << episodeNumber;
    return ss.str();
}

// Override play() to provide Podcast-specific behavior.
void Podcast::play() const {
    std::cout << "🎙️ Resuming episode " << episodeNumber << ": " << episodeTitle << " 🎙️" << std::endl;
}

