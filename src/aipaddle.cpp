#include "aipaddle.h"

AIPaddle::AIPaddle(unsigned int AiPaddleVel)
{


    AiPaddle.x = AIPaddle_X;
    AiPaddle.w = AIPaddle_W;
    AiPaddle.y = AIPaddle_Y;
    AiPaddle.h = AIPaddle_H;

    AIPaddleVelY = AiPaddleVel;
}
void AIPaddle:: Movement(unsigned rec2Y, unsigned int SCREEN_WALL)
{
 if(AiPaddle.y + 0.5*AiPaddle.h> rec2Y)AiPaddle.y -= AIPaddleVelY;
 if(AiPaddle.y + 0.5*AiPaddle.h< rec2Y)AiPaddle.y += AIPaddleVelY;
 if(AiPaddle.y < 0 ) AiPaddle.y = 0;
 if(AiPaddle.y + AiPaddle.h > SCREEN_WALL)AiPaddle.y = SCREEN_WALL-AiPaddle.h;

}
void AIPaddle::Rendering(SDL_Renderer* renderer)
{
 SDL_RenderFillRect(renderer, &AiPaddle);
}

AIPaddle::~AIPaddle()
{

}
