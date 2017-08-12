#include "paddle.h"


Paddle::Paddle(unsigned int DotV)
{


    PlayerPaddle.x = PlayerPaddle_X;
    PlayerPaddle.w = PlayerPaddle_W;
    PlayerPaddle.y = PlayerPaddle_Y;
    PlayerPaddle.h = PlayerPaddle_H;
    DotVel = DotV;
    PaddleVelY =0;
}

void Paddle::Movement(const unsigned  int &SCREEN_WALL)
{
    PlayerPaddle.y += PaddleVelY;
    if( PlayerPaddle.y < 0 ) PlayerPaddle.y = 0;
    if ( PlayerPaddle.y + PlayerPaddle.h > SCREEN_WALL )PlayerPaddle.y =SCREEN_WALL - PlayerPaddle.h;

}

void Paddle::KeyMove(SDL_Event& e)
{
    if(e.type == SDL_KEYDOWN && e.key.repeat ==0)
    {

        switch(e.key.keysym.sym)
        {
            case SDLK_w: PaddleVelY -= DotVel;  break;
            case SDLK_s: PaddleVelY += DotVel;break;
        }

    }
    else if(e.type == SDL_KEYUP && e.key.repeat == 0)
    {

        switch(e.key.keysym.sym)
        {
             case SDLK_w: PaddleVelY += DotVel; break;
            case SDLK_s: PaddleVelY -= DotVel;break;

        }

    }
}

void Paddle::Rendering(SDL_Renderer* renderer)
{

SDL_RenderFillRect( renderer, &PlayerPaddle);

}

Paddle::~Paddle()
{
    //dtor
}
