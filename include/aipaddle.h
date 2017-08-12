#ifndef AIPADDLE_H
#define AIPADDLE_H
#include "ball.h"

#include<SDL2/SDL.h>

class AIPaddle
{
    public:
        AIPaddle(unsigned int AiPaddleVel);
        void Movement(unsigned rec2Y, unsigned int SCREEN_WALL);
        void Rendering(SDL_Renderer* renderer);
        virtual ~AIPaddle();

         SDL_Rect AiPaddle;

    private:


    const unsigned int AIPaddle_X = 760;
    const unsigned int AIPaddle_Y = 250;
    const unsigned int AIPaddle_W = 20;
    const unsigned int AIPaddle_H = 100;

    int AIPaddleVelY;
};

#endif // AIPADDLE_H
