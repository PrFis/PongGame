#include "initialscreen.h"
#include"texture.h"


InitialScreen::InitialScreen(unsigned int PosX, unsigned int PosY, unsigned int WIDTH, unsigned int HIGHT)
{


RecTitle.x = PosX;
RecTitle.y = PosY;
RecTitle.w = WIDTH;
RecTitle.h =HIGHT;


}

void InitialScreen::Rendering(SDL_Renderer* renderer, SDL_Texture* mTexture)
{


//SDL_RenderClear( renderer );///Clear the screen


SDL_Rect renderQuad = { RecTitle.x, RecTitle.y, 0, 0 };

	//Set clip rendering dimensions


		renderQuad.w = RecTitle.w;
		renderQuad.h = RecTitle.h;


	//Render to screen
	SDL_RenderCopyEx( renderer, mTexture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE );

}



InitialScreen::~InitialScreen()
{
    //dtor
}
