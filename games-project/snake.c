#include "snake.h"

int area[80][30]={0};
int Column[500];
int Line[500];
int k,l;


void main_snake()
{

    int sx=40,sy=12;
    int dy=0,dx=0;
    unsigned char goal;
    int con=0;
    int a=0;

    randomize();
    make_frame(0,0,79,22,2);
    screen();


    get_cursor(2,2);printf("                                 ");
    get_cursor(2,3);printf("                                 ");
    get_cursor(2,4);printf("                                 ");
    get_cursor(2,5);printf("                                 ");
    get_cursor(2,6);printf("                                 ");
    get_cursor(2,7);printf("                                 ");
    get_cursor(2,8);printf("                                 ");
    get_cursor(2,9);printf("                                 ");
    get_cursor(2,10);printf("                                ");
     get_cursor(2,11);printf("                                ");
      get_cursor(2,12);printf("                                ");
     do
    {
        if(kbhit())
        {
            goal=getch();
            if(goal==224)				// код функциональной клавиши
            {
                goal=getch();
                switch(goal)
                {
                    case 72:dy=-1; dx=0;		//Отлов нажатия стрелочек
                        break;
                    case 80:dy=1; dx=0;
                        break;
                    case 77: dx=1; dy=0;
                        break;
                    case 75: dx=-1; dy=0;
                        break;

                }
            }
            if(goal==27){
                // если была нажата клавиша ESC
                Sleep(50);
                system ("pause"); //Чтобы сразу не пропадало окно
                printf("--Выход!--");
                con=1;
                break;
            }
        }

        sx=sx+dx;
        sy=sy+dy;
        if(sx>78) sx=2;
        if(sx<2)  sx=78;
        if(sy>22) sy=2;
        if(sy<2)  sy=22;

        Column[0]=sx;
        Line[0]=sy;
        int i;
        for(i=1;i<=a;i++)
        {
            if((sx==Column[i] && sy==Line[i]))
            {
                get_cursor(sx,sy);printf("--Ты проиграл!--");
                getch();
                con=1;
            }

        }

        get_cursor(sx,sy);printf("*");

        for(i=0;i<=a;i++)
        {
            get_cursor(Column[i],Line[i]);printf("V");

        }

        if(sx==k && sy==l)
        {
            randomize();
            a++;
            get_cursor(37,1);printf("Счёт: %d",a);
        }

        get_cursor(k,l);printf("T");

        Sleep(100);     // скорость змейки


        for(i=0;i<=a;i++)
        {
            get_cursor(Column[i],Line[i]);printf(" ");

        }

        for(i=a;i>0;i--)
        {
            Column[i]=Column[i-1];
            Line[i]=Line[i-1];
        }

    } while (con==0);
}


void make_frame(int x1, int y1, int x2, int y2, int t)			//метод для создания поля игры
{
    int i;
    for(i=x1; i<=x2;i++)
    {
        area[i][y1] = t;
        area[i][y2] = t;

    }
    for(i=y1; i<=y2;i++)
    {
        area[x1][i] = t;
        area[x2][i] = t;

    }

}

void screen()					//метод для создания окна игры
{
    int x,y;
    for(x=0;x<80;x++)
    {
        for(y=0;y<30;y++)
        {
        get_cursor(x+1,y+1);
            if(area[x][y]==1)
            {
                printf("%c",35);			// коды символов рамочки в зависимости от расположения символа
            }

            else if(area[x][y]==2)
            {
                printf("%c",35);
            }
            else if(area[x][y]==3)
                printf("%c",88);

        }
    }
    get_cursor(23,23);printf("Arrows-управление, Esc-выход");

}


randomize()					//генерация точек
{
    srand(time(NULL));
    k=4+rand()%65;
    l=4+rand()%15;
}

void get_cursor(short x, short y) {
	HANDLE ConsoleOutput;
	COORD Cursor = {x-1, y-1};
	ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(ConsoleOutput, Cursor);
}


