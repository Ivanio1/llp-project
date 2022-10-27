#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SHUFFLES 5

int player_cash;
unsigned char goal;


void play(int bet)
{

    char *positions = (char *)malloc(3 * sizeof(char));
    positions[0] = 'X';
    positions[1] = 'O';
    positions[2] = 'X';

    printf("\n����� �����...\n");

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
    printf("\n��� �����[?][?][?] - 1, 2 ��� 3? ");
    scanf("%d", &playerGuess);

    if (positions[playerGuess - 1] == 'O')
    {
        player_cash += 2 * bet;
        printf("��� ��, �� �������!!! �����: [%c] [%c] [%c] ����� ����� = $%d\n", positions[0], positions[1], positions[2], player_cash);
    }
    else
    {
        player_cash -= bet;
        printf("�� ���������, �� ��� �����������. ����� ���������� ��� ���!!! �����: [%c] [%c] [%c] ����� ����� = $%d\n", positions[0], positions[1], positions[2], player_cash);
    }
    free(positions);
}


int main_casino()
{

    int bet;
    printf("\n*** ����� ���������� � ������ 777 ***\n");
    printf("\n������ ����� ����� ����?(� ��������): ");
    scanf("%d", &player_cash);
    printf("\n����� ����� = $%d\n", player_cash);
    printf("\n��� ������ ������ �����������");
     printf("\nEsc-�����");
    while (player_cash > 0)
    {
        printf("\n������� �������? $");
        scanf("%d", &bet);

        if (bet == 0 || bet > player_cash)
        {
            printf("\n���, �� �����!!!\n");
            break;
        }

        play(bet);
        printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

        goal=getch();
         if(goal==27){
                // ���� ���� ������ ������� ESC
                Sleep(50);
                printf("--������ ���!--");
                break;
            }
    }

    return 0;
}


