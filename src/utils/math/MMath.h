#pragma once

struct Vector2
{
    float x;
    float y;
};

struct Vector2;
struct Vector2 NewVector2(float x, float y);

void PerpendicularLinePostulate(struct Vector2 a, struct Vector2 b, struct Vector2 p);
