#ifndef INITIALSCREEN_H
#define INITIALSCREEN_H
#include"texture.h"

 #include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>


class InitialScreen
{
public:
        InitialScreen(unsigned int PosX, unsigned int PosY, unsigned int WIDTH, unsigned int HIGHT);
        void Rendering(SDL_Renderer* renderer, SDL_Texture* mTexture);
        void Menu();
        void free();
        virtual ~InitialScreen();
    protected:
    private:
    SDL_Rect RecTitle;
};

#endif // INITIALSCREEN_H
