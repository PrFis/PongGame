#include "texture.h"

Texture::Texture()
{
    mTexture = NULL;


}

bool Texture::LoadTexFile(std::string FilePath, SDL_Renderer* TexRenderer)
{


//Get rid of preexisting texture
	freeTexture();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( FilePath.c_str() );

    if(loadedSurface == NULL)
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", FilePath.c_str(), IMG_GetError() );
    }
    else
    {
        ///Set color of the image
        SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format, 255, 255,255));

        newTexture=SDL_CreateTextureFromSurface(TexRenderer,loadedSurface);   //Create texture from surface pixels

        if(newTexture==NULL)
       {
            printf("Unable to create texture from %s! SDL Error: %s\n", FilePath.c_str(), SDL_GetError());
       }
       else
       {
                TexWidth = loadedSurface->w;
                TexHight = loadedSurface->h;
       }
       SDL_FreeSurface(loadedSurface); //Get rid of old surface
    }
    mTexture = newTexture;
    return mTexture != NULL;
}

void Texture::freeTexture()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		TexWidth = 0;
		TexHight = 0;
	}
}

Texture::~Texture()
{
freeTexture();
mTexture = NULL;
}
