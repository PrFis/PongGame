#ifndef SEPARATOR_H
#define SEPARATOR_H

#include<SDL2/SDL.h>

class Separator
{
    public:
        Separator(const unsigned int &SCR_WIDTH, const unsigned int &SCR_HEIGHT);
        void Rendering(SDL_Renderer *renderer);

        virtual ~Separator();
    protected:
    private:
    SDL_Rect sep[6];
};

#endif // SEPARATOR_H
