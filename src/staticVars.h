#pragma once
#include "pixelType.h"
#include "constants.h"

static sf::RenderWindow app(sf::VideoMode(w, h), "Mandelbrot Set");

static mpf_t x, y, zoom, bail;

static unsigned char pBuffer[pixelC << 2];
static pixel pixelData[pixelC];

static sf::Texture texture;
static sf::Sprite sprite(texture);

static bool draw = false;
