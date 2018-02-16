#pragma once
#include "constants.h"

sf::Thread* bots[threadCount];

inline void launchBots(sf::Thread* temp[])
{
    for(int i = 0; i < threadCount; i++)
        temp[i]->launch();
}

inline void waitBots(sf::Thread* temp[])
{
    for(int i = 0; i < threadCount; i++)
        temp[i]->wait();
}
