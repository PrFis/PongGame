#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"paddle.h"
#include"ball.h"
#include"aipaddle.h"
#include"texture.h"
#include"separator.h"
#include "script.h"
#include "initialscreen.h"
#include<string>
#include<iostream>
const unsigned int SCREEN_HEIGHT = 600;
const unsigned int SCREEN_WIDTH = 800;



SDL_Event e;
SDL_Event in;
SDL_Event occur;
SDL_Surface* screen = NULL;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;




bool LoadGame()
{

 //The surface contained by the window

  //Initialize SDL

  bool running = true;

  if( SDL_Init( SDL_INIT_VIDEO ) < 0)//Error: SDL_Init  returns -1
  {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    running = false;
  }

  else
  {
  //Create window
   window = SDL_CreateWindow( "Pong Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        ///argument 1 : name of the window, argument 2: pos x, argument 3: pos y, argument 4 :window width, argument 5:window height, argument 6 :is a flag that ensure that the window will be displayed,



        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
             running = false;
        }

         else // In case of ERROR SDL_CreateWindow returns NULL
          {
            //Get window surface

            screen = SDL_GetWindowSurface( window );


            renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );



            }

            if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					running = false;
				}




        }

return running;
}




void QuitWindow()
{
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
window = NULL;
renderer = NULL;
SDL_Quit();

}


int main(int argc, char *argv[])
{

 unsigned int BallVeloc;
unsigned int PaddleVel;
unsigned int IAPaddleVel;
Texture ObjTexInit; ///Title
unsigned int GameLevel =1;


std::string Points = "0";
SDL_Color ScriptColor = { 225, 225, 225 };
SDL_Color StartColor = { 225, 225, 0};
SDL_Color MenuColor =  {225, 225, 225};
SDL_Color EasyColor =  {225, 225, 225};
SDL_Color NormalColor =  {225, 225, 0};
SDL_Color HardColor =  {225, 225, 225};

bool StartGame = 1;
bool RenderMenu = 0;


 if(!LoadGame())
    {

       printf( "Failed to initialize!\n" );

    }
    else
    {

        bool quit = false;
        unsigned int TitleX, TitleY, TitleW, TitleH;

        TitleX = SCREEN_WIDTH/2 -200;
        TitleY = SCREEN_HEIGHT/8;
        TitleW = 400;
        TitleH = 200;

        InitialScreen InScreen(TitleX, TitleY, TitleW, TitleH);

ObjTexInit.LoadTexFile("/home/paulo/cppPro/PONG/InitialScreen/Title.bmp", renderer);
Script Start(SCREEN_WIDTH/8, SCREEN_HEIGHT/6, (0.5-0.05)*SCREEN_WIDTH - SCREEN_WIDTH/8, SCREEN_HEIGHT/1.5);
Start.LoadText("START","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, StartColor);

Script Menu(SCREEN_WIDTH/8, SCREEN_HEIGHT/6, (0.5+0.05)*SCREEN_WIDTH  , SCREEN_HEIGHT/1.5);
Menu.LoadText("LEVEL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, MenuColor);

Script Easy(SCREEN_WIDTH/8, SCREEN_HEIGHT/6, 0.5*SCREEN_WIDTH - SCREEN_WIDTH/16, SCREEN_HEIGHT/3.0-SCREEN_HEIGHT/12);
Script Normal(SCREEN_WIDTH/5, SCREEN_HEIGHT/6, 0.5*SCREEN_WIDTH - SCREEN_WIDTH/10, SCREEN_HEIGHT/2.0-SCREEN_HEIGHT/12);
Script Hard(SCREEN_WIDTH/8, SCREEN_HEIGHT/6, 0.5*SCREEN_WIDTH - SCREEN_WIDTH/16, SCREEN_HEIGHT/1.5-SCREEN_HEIGHT/12);

  Easy.LoadText("EASY","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, EasyColor);

  Normal.LoadText("NORMAL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, NormalColor);

    Hard.LoadText("HARD","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, HardColor);

           while(!quit)
        {

            if(SDL_PollEvent(&in) != 0)
            {

                if( in.type == SDL_QUIT )
					{
						quit = true;
					}
                     if(in.type == SDL_KEYDOWN && in.key.repeat ==0)
					{


                        switch(in.key.keysym.sym)
                        {
                            case SDLK_RIGHT:
                                 StartColor = { 225, 225, 225};
                                 MenuColor =  {225, 225, 0};
                                Start.LoadText("START","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, StartColor);
                                Menu.LoadText("LEVEL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, MenuColor);
                                StartGame = 0;
                                break;
                            case SDLK_LEFT:
                                 StartColor = { 225, 225, 0};
                                 MenuColor =  {225, 225, 225};
                                Start.LoadText("START","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, StartColor);
                                Menu.LoadText("LEVEL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, MenuColor);
                                StartGame = 1;
                                break;
                            case SDLK_UP:
                                if(NormalColor.b == 0)
                                {
                                    EasyColor.b = 0;
                                    NormalColor.b = 225;
                                    GameLevel = 0;
                                    Easy.LoadText("EASY","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, EasyColor);
                                    Normal.LoadText("NORMAL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, NormalColor);
                                }
                                 if(HardColor.b == 0)
                                {
                                    NormalColor.b = 0;
                                    HardColor.b = 225;
                                    GameLevel = 1;
                                    Hard.LoadText("HARD","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, HardColor);
                                    Normal.LoadText("NORMAL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, NormalColor);
                                }
                                break;

                            case SDLK_DOWN:
                            if(NormalColor.b == 0)
                                {
                                    HardColor.b = 0;
                                    NormalColor.b = 225;
                                    GameLevel = 2;
                                    Normal.LoadText("NORMAL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, NormalColor);
                                    Hard.LoadText("HARD","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, HardColor);
                                }
                                 if(EasyColor.b == 0)
                                {
                                    NormalColor.b = 0;
                                    EasyColor.b = 225;
                                    GameLevel = 1;
                                    Normal.LoadText("NORMAL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, NormalColor);
                                    Easy.LoadText("EASY","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, EasyColor);
                                }
                            break;

                        }

                            if((in.key.keysym.sym == SDLK_RETURN)&&(StartGame == 1))break;
                            if((in.key.keysym.sym == SDLK_RETURN)&&(StartGame == 0))
                            {
                                if(RenderMenu ==0)RenderMenu =1;
                                else RenderMenu =0;
                            }




					}




            }
             SDL_RenderClear( renderer );
              SDL_SetRenderDrawColor( renderer,0, 0, 0, 0);
              if(RenderMenu==0)
              {
                InScreen.Rendering(renderer, ObjTexInit.mTexture);
                Start.Rendering(renderer);
                Menu.Rendering(renderer);
              }
              else
              {

            Easy.Rendering(renderer);
            Normal.Rendering(renderer);
            Hard.Rendering(renderer);
            }
              SDL_RenderPresent(renderer);

    }
    ObjTexInit.freeTexture();

        if(GameLevel ==0)
        {
            BallVeloc =6;
             PaddleVel = 7;
             IAPaddleVel = 6;
        }
        else if(GameLevel ==1)
        {
            BallVeloc =8;
             PaddleVel = 7;
             IAPaddleVel = 7;
        }
        else
        {
            BallVeloc =9;
             PaddleVel = 7;
             IAPaddleVel = 9;
        }



        Texture ObjTex;
        Paddle Player(PaddleVel);
        AIPaddle Enemy(IAPaddleVel);
        Ball BallGame(BallVeloc);
        Separator LineSeparator(SCREEN_WIDTH, SCREEN_HEIGHT);
        Script PlayerScore(SCREEN_WIDTH/24, SCREEN_HEIGHT/8, SCREEN_WIDTH/4 - 0.5*SCREEN_WIDTH/12 -3, SCREEN_HEIGHT/24);
        Script EnemyScore(SCREEN_WIDTH/24, SCREEN_HEIGHT/8, 3*SCREEN_WIDTH/4 - 0.5*SCREEN_WIDTH/12 +3, SCREEN_HEIGHT/24);

        ObjTex.LoadTexFile("/home/paulo/cppPro/PONG/Textures/Ball.bmp", renderer);
        PlayerScore.LoadText("0","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, ScriptColor);
        EnemyScore.LoadText("0","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf", 40, renderer, ScriptColor);
         unsigned int PlayerScorePoints =0;
         unsigned int EnemyScorePoints=0;
           Script Winner(SCREEN_WIDTH/3.5, SCREEN_HEIGHT/3.5, 0.5*SCREEN_WIDTH - SCREEN_WIDTH/7, SCREEN_HEIGHT/3.0-SCREEN_HEIGHT/12);
            Winner.LoadText("NORMAL","/home/paulo/cppPro/PONG/Fonts/LatinModernSansQuotation.ttf",   40, renderer, ScriptColor);
         bool Final =false;
        while(!quit)
        {

            while(SDL_PollEvent(&e) != 0)
            {
                if( e.type == SDL_QUIT )
					{
						quit = true;

					}

                Player.KeyMove(e);


            }

         if(Final==false)
         {

          BallGame.Movement(&Player.PlayerPaddle, &Enemy.AiPaddle, SCREEN_HEIGHT, SCREEN_WIDTH);
         Enemy.Movement(BallGame.Pongball.y+ BallGame.Pongball.h, SCREEN_HEIGHT);
         Player.Movement(SCREEN_HEIGHT);

         if(BallGame.RPlayerPoints() ==true)
         {


            PlayerScorePoints = BallGame.EncreasePlayerPoint();
            Points = std::to_string(PlayerScorePoints);

            PlayerScore.LoadFromText(Points,  renderer, ScriptColor);
            BallGame.ResetPointsBool();
         }

         else if(BallGame.REnemyPoints() ==true)
         {

            EnemyScorePoints = BallGame.EncreaseEnemyPoint();
            Points = std::to_string(EnemyScorePoints);
            EnemyScore.LoadFromText(Points, renderer, ScriptColor);
            BallGame.ResetPointsBool();


        }
        }

        if(PlayerScorePoints>9)
        {
        Winner.LoadFromText("YOU WON!", renderer, ScriptColor);
        Final = true;
        }

        if(EnemyScorePoints>9)
        {
        Winner.LoadFromText("YOU LOSE!", renderer, ScriptColor);
        Final = true;
        }
         SDL_RenderClear( renderer );
        SDL_SetRenderDrawColor( renderer,225, 225, 225, 225);

         if(Final ==true)
         {
            Winner.Rendering(renderer);

         }
         else
         {
            BallGame.Rendering(renderer, ObjTex.mTexture);
            LineSeparator.Rendering(renderer);
         }




         Player.Rendering(renderer);

         Enemy.Rendering(renderer);

         PlayerScore.Rendering(renderer);
         EnemyScore.Rendering(renderer);

         //Redering(Player.PlayerPaddle, Enemy.AiPaddle, BallGame.Pongball, ObjTex.mTexture);
         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderPresent(renderer);


        }



    }


QuitWindow();




    return 0;
}
