#include "script.h"


Script::Script(const unsigned int &TextBoxWidth, const unsigned int &TextBoxHeight,const unsigned int &TextBoxX, const unsigned int &TextBoxY)
{

TextBox.w = TextBoxWidth;
TextBox.h = TextBoxHeight;
TextBox.x = TextBoxX;
TextBox.y = TextBoxY;
mTexture = NULL;

gFont = NULL;
}

bool Script::LoadText(std::string Score, std::string Fontfile,   unsigned int FontSize, SDL_Renderer* renderer, SDL_Color textColor)
{
bool success = true;



	//Open the font
	gFont = TTF_OpenFont( Fontfile.c_str(), FontSize);
	if( gFont == NULL )
	{
		printf( "Failed to load font file! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		 //textColor = { 225, 225, 225 };
		if( !LoadFromText(Score,  renderer, textColor ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}

bool Script::LoadFromText(std::string textureText,  SDL_Renderer* renderer, SDL_Color textColor)
{
	//Get rid of preexisting texture
 free();



	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}


	//Return success

	return mTexture != NULL;
}



void Script::Rendering(SDL_Renderer* renderer)
{


//SDL_RenderClear( renderer );///Clear the screen


SDL_Rect renderQuad = { TextBox.x, TextBox.y, mWidth, mHeight};




		renderQuad.w = TextBox.w;
		renderQuad.h = TextBox.h;


	//Render to screen
	SDL_RenderCopyEx( renderer, mTexture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE );

}



void Script::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
	    mWidth = 0;
		mHeight = 0;
	}
}

Script::~Script()
{

TTF_CloseFont( gFont );
	gFont = NULL;
	TTF_Quit();

}
