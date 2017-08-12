#ifndef BALL_H
#define BALL_H
#include "script.h"

#include<SDL2/SDL.h>
#include<stdlib.h>


class Ball
{
    public:

        Ball(unsigned int BallVel);
        bool Collision(SDL_Rect* rec1, SDL_Rect* rec2);
        bool UpCollision (SDL_Rect* rectan);
        bool DownCollision(SDL_Rect* rectan);
        void Movement(SDL_Rect* rec1, SDL_Rect* rec2, unsigned int SCREEN_WALLY, unsigned int SCREEN_WALLX);
        void Reset();
        void ResetPointsBool();
        int GetRandomNumber(int high, int low);
        void Rendering(SDL_Renderer* renderer, SDL_Texture* mTexture);

        inline unsigned int EncreasePlayerPoint(){return ++PlayerPoint;}
        inline unsigned int EncreaseEnemyPoint(){return ++EnemyPoint;}
        inline bool RPlayerPoints(){return PlayerPoints;}
        inline bool REnemyPoints(){return EnemyPoints; }
        virtual ~Ball();

        SDL_Rect Pongball;

    protected:


    private:
     const  unsigned int Ball_X = 390;
     const  unsigned int Ball_Y = 290;
     const  unsigned int Ball_W = 20;
     const  unsigned int Ball_H = 20;

     unsigned int PlayerPoint;
     unsigned int EnemyPoint;

    bool PlayerPoints, YCol;
    bool EnemyPoints;
    unsigned int BallVelocity;

    int Ball_VelX, Multplier;
    int Ball_VelY;
};

#endif // BALL_H
