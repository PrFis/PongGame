#ifndef PADDLE_H
#define PADDLE_H

#include<SDL2/SDL.h>

class Paddle
{

    public:
        Paddle(unsigned int DotV);
        void Movement(const unsigned int &SCREEN_WALL);
        void KeyMove(SDL_Event& e);
        void Rendering(SDL_Renderer* renderer);
        virtual ~Paddle();

    SDL_Rect PlayerPaddle;

    private:



        const unsigned int PlayerPaddle_X = 20; ///x Position of the rectangle in pixels
        const unsigned int PlayerPaddle_Y = 250;
        const unsigned int PlayerPaddle_H = 100;///Hight
        const unsigned int PlayerPaddle_W = 20;///Width
        unsigned int DotVel;


        int PaddleVelY;
};

#endif // PADDLE_H
