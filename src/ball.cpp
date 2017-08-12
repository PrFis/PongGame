#include "ball.h"

#include<ctime>

using namespace std;
Ball::Ball(unsigned int BallVel)
{


    Multplier = 1;
    Pongball.w = Ball_W;
    Pongball.h = Ball_H;

  srand(time(NULL));

   BallVelocity = BallVel;
  Reset();
  ResetPointsBool();
  PlayerPoint = 0;
  EnemyPoint = 0;


}
void Ball::Reset()
{
Pongball.x = Ball_X;
Pongball.y = Ball_Y;

Ball_VelX = Multplier*BallVelocity*GetRandomNumber(1,-1);
Ball_VelY =Multplier*Multplier*BallVelocity*GetRandomNumber(1,-1);
YCol = 0;

Multplier*=-1;
}
void Ball::ResetPointsBool()
{
PlayerPoints = false;
EnemyPoints = false;
}
void Ball:: Movement(SDL_Rect* rec1, SDL_Rect* rec2, unsigned int SCREEN_WALLY, unsigned int SCREEN_WALLX)
{


Pongball.x += Ball_VelX;
Pongball.y += Ball_VelY;


if((UpCollision(rec1) == 1)||(UpCollision(rec2)==1)||(DownCollision(rec1) == 1)||(DownCollision(rec2)==1))
{
    if(YCol == 0)
    {
        Ball_VelY = -Ball_VelY;
        YCol =1;
    }
    else Ball_VelY += 3;

}
else{
    if((Collision(&Pongball, rec1)==1)&&(Pongball.x+Pongball.w>rec1->x)&&(YCol == 0))
    {

        if((Pongball.y+Pongball.h/2.0)<(rec1->y+rec1->h/2.0)) Ball_VelY-=1;
         else if((Pongball.y+Pongball.h/2.0)>(rec1->y+rec1->h/2.0)) Ball_VelY+=1;

        Ball_VelX = -Ball_VelX;

        Pongball.x = rec1->x + rec1->w;
    }
    if((Collision(&Pongball, rec2)==1)&&(Pongball.x<rec2->x+rec2->w)&&(YCol == 0))
    {
        if((Pongball.y+Pongball.h/2.0)<(rec2->y+rec2->h/2.0)) Ball_VelY-=1;
         else if((Pongball.y+Pongball.h/2.0)>(rec2->y+rec2->h/2.0)) Ball_VelY+=1;
        Ball_VelX = -Ball_VelX;

        Pongball.x = rec2->x- Pongball.w;
    }
    if(Pongball.y<1) Ball_VelY= -Ball_VelY;
    if(Pongball.y + Pongball.h> SCREEN_WALLY)Ball_VelY= -Ball_VelY;
    if(Pongball.x<1)
    {
        EnemyPoints = true;
        Reset();
    }
    if(Pongball.x + Pongball.w> SCREEN_WALLX){
     PlayerPoints = true;
     Reset();
    }
}

}



  bool Ball::Collision(SDL_Rect* rec1, SDL_Rect* rec2)

{

    if(rec1->y > rec2-> y + rec2 ->h)return 0;

    else if (rec1->x > rec2->x + rec2->w)return 0;

    else if(rec1->y + rec1->h<rec2->y) return 0;


   else if(rec1->x+rec2->w <rec2->x) return 0;



    else return 1;
}


bool Ball::UpCollision(SDL_Rect* rectan)
{

SDL_Rect UpEdge;

UpEdge.w = rectan->w-2;
UpEdge.h = 0;
UpEdge.x = rectan->x+1;
UpEdge.y = rectan->y;

if(Collision(&Pongball, &UpEdge)==true)
{
    Pongball.y = UpEdge.y;
    return 1;
}

return 0;

}

bool Ball::DownCollision(SDL_Rect *rectan)
{

SDL_Rect DownEdge;


DownEdge.w = rectan->w-2;
DownEdge.h = 0;
DownEdge.x = rectan->x+1;
DownEdge.y = rectan->y + rectan->h;

if(Collision(&Pongball, &DownEdge)==true)
{
    Pongball.y = DownEdge.y;
    return 1;
}
return 0;

}


 int Ball::GetRandomNumber(int high, int low)
{
    return rand() % high + low;
}

void Ball::Rendering(SDL_Renderer* renderer, SDL_Texture* mTexture)
{


//SDL_RenderClear( renderer );///Clear the screen


SDL_Rect renderQuad = { Pongball.x, Pongball.y, 0, 0 };

	//Set clip rendering dimensions


		renderQuad.w = Pongball.w;
		renderQuad.h = Pongball.h;


	//Render to screen
	SDL_RenderCopyEx( renderer, mTexture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE );

}


Ball::~Ball()
{

}
