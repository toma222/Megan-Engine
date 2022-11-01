#pragma once

struct Vector2
{
    int x;
    int y;
};

struct Vector2;
struct Vector2 NewVector2(int x, int y);

void PerpendicularLinePostulate(struct Vector2 a, struct Vector2 b, struct Vector2 p);
