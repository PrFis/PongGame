#include "separator.h"

Separator::Separator(const unsigned int &SCR_WIDTH,const unsigned int &SCR_HEIGHT)
{

unsigned int TraceWidth = 6;
for(unsigned int i = 0 ; i < 8 ; i++)
{
    sep[i] = {SCR_WIDTH/2- TraceWidth/2, i*2*SCR_HEIGHT/15, TraceWidth, SCR_HEIGHT/15};
}

}

void Separator::Rendering(SDL_Renderer *renderer)
{
for(unsigned int i = 0 ; i < 8 ; i++)
{
    SDL_RenderFillRect(renderer,&sep[i]);

}

}
Separator::~Separator()
{
    //dtor
}
