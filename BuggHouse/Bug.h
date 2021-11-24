#pragma once
#include "Actor.h"
class Bug :
    public Actor
{
    enum class Direction
    {
        UP,
        UP_RIGHT,
        RIGHT,
        DOWN_RIGHT,
        DOWN,
        DOWN_LEFT,
        LEFT,
        UP_LEFT,
        COUNT
    };

    Direction mDir{ Direction::UP };
    int mSteps;


public :
    Bug(D2DFramework* pFramework);

    virtual void Draw() override;
};

