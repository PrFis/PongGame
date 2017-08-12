#ifndef SCRIPT_H
#define SCRIPT_H

#include"ball.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<string>


class Script
{


    public:
        Script(const unsigned int &TextBoxWidth, const unsigned int &TextBoxHeight, const unsigned int &TextBoxX, const unsigned int &TextBoxY);
        bool LoadText(std::string Score, std::string Fontfile,   unsigned int Fontsize, SDL_Renderer* renderer, SDL_Color textColor);
        bool LoadFromText(std::string textureText,  SDL_Renderer* renderer, SDL_Color textColor);
        void free();
        void Rendering(SDL_Renderer* renderer);

        virtual ~Script();
        //friend class Ball;
    protected:

    private:
    SDL_Texture* mTexture;
    SDL_Rect TextBox;
    std::string FontFile;
    std::string textureText;
    unsigned int mWidth;
	unsigned int mHeight;
    //SDL_Color textColor;

	TTF_Font *gFont;

};

#endif // SCRIPT_H
