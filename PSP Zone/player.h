#include "gfx.h"

class player
{
public:
    int x;
    int y;
    void move(int x);
    void draw();
    player(int x){
        this->x = x;
        this->y = 194;
    }
    ~player(){

    };
};