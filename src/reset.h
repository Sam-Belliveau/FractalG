#pragma once
#include "includes.h"

void resetNums()
{
    mpf_t ratio, xStart, xIter, yIter, py, px;
    mpf_init2(ratio, p); mpf_init2(xStart, p); mpf_init2(xIter, p); mpf_init2(yIter, p); mpf_init2(py, p); mpf_init2(px, p);

    mpf_set_d(ratio, ((double)app.getSize().x)/((double)app.getSize().y));
    mpf_sub(xStart, x, zoom);
    mpf_mul_ui(xIter, ratio, 2); mpf_mul(xIter, xIter, zoom); mpf_div_ui(xIter, xIter, w);
    mpf_mul_ui(yIter, zoom, 2); mpf_div_ui(yIter, yIter, h);
    mpf_add(py,py,y); mpf_sub(py,py,zoom);
    unsigned int i = 0;
    for(unsigned int iy = 0; iy < h; iy++)
    {
        mpf_set(px, xStart);
        for(unsigned int ix = 0; ix < w; ix++)
        {
            mpf_set(pixelData[i].cr, px); mpf_set(pixelData[i].ci, py);
            mpf_set(pixelData[i].zr, px); mpf_set(pixelData[i].zi, py);
            pixelData[i].iteration = 0; pixelData[i].state = false;
            pBuffer[i*4 + 0] = 0; pBuffer[i*4 + 1] = 0;
            pBuffer[i*4 + 2] = 0; pBuffer[i*4 + 3] = 255;
            mpf_add(px, px, xIter); i++;
        } mpf_add(py, py, yIter);
    }
    mpf_clear(ratio); mpf_clear(xStart); mpf_clear(xIter); mpf_clear(yIter); mpf_clear(py); mpf_clear(px);
}

void reset(){ mpf_set_d(x,-1.5); mpf_set_d(y,0); mpf_set_d(zoom,2); }
