#include "includes.h"
#include "colors.h"
#include "pixelType.h"
#include "constants.h"

void iterate(pixel &temp)
{
    if(temp.state) { return; }

    mpf_t sqzr, sqzi, comp;
    mpf_init2(sqzr, p); mpf_init2(sqzi, p); mpf_init2(comp, p);

    mpf_mul(sqzr, temp.zr, temp.zr);    /// sqzr = zr*zr
    mpf_mul(sqzi, temp.zi, temp.zi);    /// sqzi = zi*zi
    mpf_mul(temp.zi, temp.zr, temp.zi); /// zi = 2*zr*zi + ci
    mpf_add(temp.zi, temp.zi, temp.zi); /// |
    mpf_add(temp.zi, temp.zi, temp.ci); /// |
    mpf_sub(temp.zr, sqzr, sqzi);       /// zr = cr + sqzr - sqzi
    mpf_add(temp.zr, temp.zr, temp.cr); /// |
    mpf_mul(sqzr, temp.zr, temp.zr); /// sqzr = zr*zr
    mpf_mul(sqzi, temp.zi, temp.zi); /// sqzi = zi*zi
    mpf_add(comp, sqzr, sqzi); /// Adding squares for compairison

    if(mpf_cmp(comp, bail) > 0) { temp.state = true; }
    else { temp.iteration++; }

    mpf_clear(sqzr); mpf_clear(sqzi); mpf_clear(comp);
}

void drawFract(const unsigned int threadNum)
{
    const unsigned int max = (pixelC / threadCount) * (1 + threadNum);
    for(unsigned int pix = (pixelC / threadCount) * threadNum; pix < max; pix++)
    {
        iterate(pixelData[pix]);

        const unsigned int counter = pix << 2;
        if(pixelData[pix].state)
        {
            if(!draw) { draw = true; }

            const unsigned long ii = pixelData[pix].iteration%color::count;
            pBuffer[counter + 0] = color::r[ii];
            pBuffer[counter + 1] = color::g[ii];
            pBuffer[counter + 2] = color::b[ii];
        }
    }
}

void drawPixels()
{
    texture.update(pBuffer);
    app.draw(sprite);
    app.display();
}
