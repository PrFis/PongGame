#ifndef TEXTURE_H
#define TEXTURE_H

#include<SDL2/SDL.h>
 #include<SDL2/SDL_image.h>
#include<string>

class Texture
{
    public:
        Texture();
        SDL_Texture* mTexture;
        bool LoadTexFile(std::string FilePath, SDL_Renderer* TexRenderer);
        void freeTexture();
        virtual ~Texture();
    protected:
    private:

    unsigned int TexWidth =0;
    unsigned int TexHight =0;
};

#endif // TEXTURE_H
