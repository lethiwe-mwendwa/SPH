#include "player.h"

void player::move(int x){
    this->x = this->x + x;
}

void player::draw(){
    GFX::drawRect(this->x,this->y+30, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x,this->y+40, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x,this->y+50, 10, 10, 0xFFFFFFFF);

    GFX::drawRect(this->x+9,this->y+20, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+9,this->y+30, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+9,this->y+40, 10, 10, 0xFFFFFFFF);

    GFX::drawRect(this->x+19,this->y+10, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+19,this->y+20, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+19,this->y+30, 10, 10, 0xFFFFFFFF);

    GFX::drawRect(this->x+29,this->y,10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+29,this->y+10, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+29,this->y+20, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+29,this->y+30, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+29,this->y+40, 10, 10, 0xFFFFFFFF);

    GFX::drawRect(this->x+39,this->y+10, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+39,this->y+20, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+39,this->y+30, 10, 10, 0xFFFFFFFF);

    GFX::drawRect(this->x+49,this->y+20, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+49,this->y+30, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+49,this->y+40, 10, 10, 0xFFFFFFFF);

    GFX::drawRect(this->x+59,this->y+30, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+59,this->y+40, 10, 10, 0xFFFFFFFF);
    GFX::drawRect(this->x+59,this->y+50, 10, 10, 0xFFFFFFFF);
}