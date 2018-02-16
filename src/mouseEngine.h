#include "includes.h"

void updateMouse()
{
    mpf_t modx, mody;
    mpf_t zmod;
    mpf_t tx, ty;
    mpf_t wRatio, hRatio, ratio;
    mpf_init2(modx, p);
    mpf_init2(mody, p);
    mpf_init2(zmod, p);
    mpf_init2(tx, p);
    mpf_init2(ty, p);
    mpf_init2(wRatio, p);
    mpf_init2(hRatio, p);
    mpf_init2(ratio, p);
    while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
    mpf_set_ui(ratio, app.getSize().y);
    mpf_div_ui(ratio, ratio, app.getSize().x);
    mpf_set_ui(wRatio, w);
    mpf_div_ui(wRatio, wRatio, app.getSize().x);
    mpf_set_ui(hRatio, h);
    mpf_div_ui(hRatio, hRatio, app.getSize().y);
    mpf_set_ui(tx, sf::Mouse::getPosition(app).x);
    mpf_mul(tx,tx,wRatio);
    mpf_set_ui(ty, sf::Mouse::getPosition(app).y);
    mpf_mul(ty,ty,hRatio);
    mpf_set_ui(modx, w);
    mpf_div_ui(modx, modx, 2);
    mpf_mul(modx, modx, ratio);
    mpf_set_ui(mody, h);
    mpf_div_ui(mody, mody, 2);
    mpf_sub(tx, tx, modx);
    mpf_sub(ty, ty, mody);
    mpf_mul(tx, tx, zoom);
    mpf_mul(ty, ty, zoom);
    mpf_div(tx, tx, modx);
    mpf_div(ty, ty, mody);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
    mpf_set_d(zmod, -3);
    mpf_mul(tx,tx,zmod);
    mpf_mul(ty,ty,zmod);
    mpf_add(x,x,tx);
    mpf_add(y,y,ty);
    mpf_mul_ui(zoom, zoom, 4);
    }
    else
    {
    mpf_set_d(zmod, 3.f/4.f);
    mpf_mul(tx,tx,zmod);
    mpf_mul(ty,ty,zmod);
    mpf_add(x,x,tx);
    mpf_add(y,y,ty);
    mpf_div_ui(zoom, zoom, 4);
    }
    draw = false;
    mpf_clear(modx);
    mpf_clear(mody);
    mpf_clear(zmod);
    mpf_clear(tx);
    mpf_clear(ty);
    mpf_clear(wRatio);
    mpf_clear(hRatio);
    mpf_clear(ratio);
}
