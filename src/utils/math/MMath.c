
#include "MMath.h"

struct Vector2 NewVector2(int x, int y)
{
    struct Vector2 v = {x, y};
    return v;
}

void PerpendicularLinePostulate(struct Vector2 a, struct Vector2 b, struct Vector2 p){
    float lSlope = (a.y - b.y) / (a.x - b.x);
    float lIntercept = a.y - (lSlope * a.x);

    float mSlope = (-1) / lSlope;
    float mIntercept = p.y - (mSlope * p.x);

    float x = (mIntercept - lIntercept) / (mSlope - lSlope);
    float y; 

    // return NewVector2(0,0);
}
