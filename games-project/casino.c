#include "casino.h"

int player_cash;
unsigned char goal;


void play(int bet)
{
    char *positions = (char *)malloc(3 * sizeof(char));
    positions[0] = 'X';
    positions[1] = 'O';
    positions[2] = 'X';

    printf("\nКручу верчу...\n");

    srand(time(NULL));

    for (int i = 0; i < SHUFFLES; i++)
    {

        int x = rand() % 3;
        int y = rand() % 3;


        int temp = positions[x];
        positions[x] = positions[y];
        positions[y] = temp;
    }

    int playerGuess;
    printf("\nГде мячик[?][?][?] - 1, 2 или 3? ");
    scanf("%d", &playerGuess);

    if (positions[playerGuess - 1] == 'O')
    {
        player_cash += 2 * bet;
        printf("Ооо да, вы угадали!!! Шарик: [%c] [%c] [%c] Общая сумма = $%d\n", positions[0], positions[1], positions[2], player_cash);
    }
    else
    {
        player_cash -= bet;
        printf("Вы проиграли, но это случайность. Стоит поробовать еще раз!!! Шарик: [%c] [%c] [%c] Общая сумма = $%d\n", positions[0], positions[1], positions[2], player_cash);
    }
    free(positions);
}


int main_casino()
{
    int bet;
    printf("\n*** Добро пожаловать в КАЗИНО 777 ***\n");
    printf("\nКакова общая сумма игры?(В долларах): ");
    scanf("%d", &player_cash);
    printf("\nОбщая сумма = $%d\n", player_cash);
    printf("\nПри победе ставка удваивается");
    printf("\nEsc-выход");
    while (player_cash > 0)
    {
        printf("\nСколько ставите? $");
        scanf("%d", &bet);

        if (bet == 0 || bet > player_cash)
        {
            printf("\nУвы, Вы нищий!!!\n");
            getch();
            break;

        }

        play(bet);
        printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

        goal=getch();
         if(goal==27){
                // если была нажата клавиша ESC
                Sleep(50);
                printf("--Заходи ещё!--");
                getch();
                break;
            }
    }

    return 0;
}


