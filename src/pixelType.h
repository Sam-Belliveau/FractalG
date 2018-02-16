#pragma once
#include "includes.h"
#include "constants.h"

struct pixel
{
    unsigned int iteration;
    bool state; mpf_t cr, ci, zr, zi;

    pixel()
    {
        iteration = 0; state = false;
        mpf_init2(cr,p); mpf_init2(ci,p);
        mpf_init2(zr,p); mpf_init2(zi,p);
    }
};
