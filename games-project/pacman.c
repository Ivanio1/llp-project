#include "pacman.h"

struct coord
{
   int x;
   int y;
};

struct PacMan {
   struct coord position;
   int vx;
   int vy;
   int lives;
   bool chasing;
   int food_collected;
};


struct Ghost {
   struct coord position;
   int vx;
   int vy;
   bool chasing;
};


struct Ghost allGhosts[GHOSTS];

struct PacMan myPacMan = {
                           {
                              .x = 1,
                              .y = 1,
                           },
                           .vx = 0,
                           .vy = 0,
                           .lives = 3,
                           .chasing = false,
                           .food_collected = 0
                         };

char playfield[H][W] =
{
   { "############################################################" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#            # # #                    #        #           #" },
   { "#          #                        #   #    #  #          #" },
   { "#          #     #                 #     #  #    #         #" },
   { "#           # # #                 #       #       #        #" },
   { "#            #   #                #               #        #" },
   { "#           #                       #           #          #" },
   { "#          #     #                    #       #            #" },
   { "#         #                             #   #              #" },
   { "#        #       #                        #                #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                 # # #    # # # # # #                     #" },
   { "#               #          #         #                     #" },
   { "#               #     #    #         #                     #" },
   { "#                # # #     #         #                     #" },
   { "#                 #   #    #         #                     #" },
   { "#                #         #         #                     #" },
   { "#               #     #    #         #                     #" },
   { "#              #           #         #                     #" },
   { "#             #       #    #         #                     #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }
};


void initialize()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (playfield[i][j]==' ')
            playfield[i][j] = '.';
      }
   }
fill_ghosts();
}
void fiil_ghosts(){
  for (int i = 0; i < GHOSTS; i++)
   {
      allGhosts[i].vx = 0;
      allGhosts[i].vy = 0;
      allGhosts[i].chasing = true;

      int x,y;
      do
      {
         x = 1 + rand() % (W-1);
         y = 1 + rand() % (H-1);

      } while (playfield[y][x] != '.');
      allGhosts[i].position.x = x;
      allGhosts[i].position.y = y;
      playfield[y][x] = 'G';

   }
  
}

void user_click()
{
   if (_kbhit())
   {
      char c1 = _getch();

      if (c1 == -32)
      {
         char c2 = _getch();

         myPacMan.vx = 0;
         myPacMan.vy = 0;

         switch (c2)
         {
            case 72: myPacMan.vy = -1; break; // cursor up
            case 80: myPacMan.vy = +1; break; // cursor down
            case 75: myPacMan.vx = -1; break; // cursor left
            case 77: myPacMan.vx = +1; break; // cursor right

         }
      }
      if(c1==27){
                //если была нажата клавиша ESC
                Sleep(50);
                printf("--Выход!--");
                system ("pause"); //Чтобы сразу не пропадало окно
                _Exit(EXIT_SUCCESS);
            }


   }
}


void move_figures()
{
   playfield[myPacMan.position.y][myPacMan.position.x] = ' ';

   int nx = myPacMan.vx + myPacMan.position.x;
   int ny = myPacMan.vy + myPacMan.position.y;

   if (playfield[ny][nx] == '#')
   {
      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }

   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;

   if (playfield[ny][nx] == '.')
   {
      myPacMan.food_collected++;
   }
   if (playfield[ny][nx] == 'G')
   {
      myPacMan.lives--;
   }
   if(myPacMan.lives==0){
                Sleep(50);
                printf("--Игра окончена!Вы потратили все 3 жизни!--");
                getch();
                return;
   }

   playfield[myPacMan.position.y][myPacMan.position.x] = 'P';


}



void show_playfield()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", playfield[i][j]);
      }
      printf("\n");
   }

   printf("Score: %d\n", myPacMan.food_collected);
}



void set_cursor_position(int x, int y)
{
   COORD coord = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


int main_pacman()
{
   system("cls");
   hidecursor();
   initialize();

   while (1)
   {
      user_click();
      move_figures();
      show_playfield();
      Sleep(30);
      set_cursor_position(0,0);


   }

}

