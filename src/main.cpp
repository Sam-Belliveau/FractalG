#include "includes.h"
#include "renderEngine.h"
#include "mouseEngine.h"
#include "pixelType.h"
#include "constants.h"
#include "threads.h"
#include "colors.h"
#include "reset.h"

int main()
{
    for(int i = 0; i < threadCount; i++)
        bots[i] = new sf::Thread(drawFract, i);

    mpf_init2(bail, p);
    mpf_set_ui(bail, 4);

    mpf_init2(x, p);
    mpf_init2(y, p);
    mpf_init2(zoom, p);

    texture.create(w,h);
    texture.setSmooth(false);

    reset();
    resetNums();

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        draw = false;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            updateMouse();
            resetNums();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            reset();
            resetNums();
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {}
        }

        launchBots(bots);
        waitBots(bots);
        if(draw)
        {
            drawPixels();
        }
    }

    return EXIT_SUCCESS;
}
