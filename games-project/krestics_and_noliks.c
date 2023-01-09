#include "krestics_and_noliks.h"

char kvadrat[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int main_kandn()
{
    int player = 1, i, vibor;
    char mark;
				
    do
    {
	board();
	player = (player % 2) ? 1 : 2;

	printf("\t\t\tИгрок %d, введите число:  ", player);
	scanf("%d", &vibor);

	mark = (player == 1) ? 'X' : 'O';

	if (vibor == 1 && kvadrat[1] == '1')
	    kvadrat[1] = mark;

	else if (vibor == 2 && kvadrat[2] == '2')
	    kvadrat[2] = mark;

	else if (vibor == 3 && kvadrat[3] == '3')
	    kvadrat[3] = mark;

	else if (vibor == 4 && kvadrat[4] == '4')
	    kvadrat[4] = mark;

	else if (vibor == 5 && kvadrat[5] == '5')
	    kvadrat[5] = mark;

	else if (vibor == 6 && kvadrat[6] == '6')
	    kvadrat[6] = mark;

	else if (vibor == 7 && kvadrat[7] == '7')
	    kvadrat[7] = mark;

	else if (vibor == 8 && kvadrat[8] == '8')
	    kvadrat[8] = mark;

	else if (vibor == 9 && kvadrat[9] == '9')
	    kvadrat[9] = mark;

	else
	{
	    printf("\t\t\tХитрюга, так нельзя! ");

	    player--;
	    getch();
	}
	i = check_win();

	player++;
    }
				while (i ==  - 1);

    board();

    if (i == 1)
	printf("\t\t\t==>\aИгрок %d выиграл ", --player);
    else
	printf("\t\t\t==>\aИгра закончена ");
    system ("pause"); //Чтобы сразу не пропадало окно


    getch();

    return 0;
}



int check_win()
{
    if (kvadrat[1] == kvadrat[2] && kvadrat[2] == kvadrat[3])
	return 1;

    else if (kvadrat[4] == kvadrat[5] && kvadrat[5] == kvadrat[6])
	return 1;

    else if (kvadrat[7] == kvadrat[8] && kvadrat[8] == kvadrat[9])
	return 1;

    else if (kvadrat[1] == kvadrat[4] && kvadrat[4] == kvadrat[7])
	return 1;

    else if (kvadrat[2] == kvadrat[5] && kvadrat[5] == kvadrat[8])
	return 1;

    else if (kvadrat[3] == kvadrat[6] && kvadrat[6] == kvadrat[9])
	return 1;

    else if (kvadrat[1] == kvadrat[5] && kvadrat[5] == kvadrat[9])
	return 1;

    else if (kvadrat[3] == kvadrat[5] && kvadrat[5] == kvadrat[7])
	return 1;

    else if (kvadrat[1] != '1' && kvadrat[2] != '2' && kvadrat[3] != '3' &&
	kvadrat[4] != '4' && kvadrat[5] != '5' && kvadrat[6] != '6' && kvadrat[7]
	!= '7' && kvadrat[8] != '8' && kvadrat[9] != '9')

	return 0;
    else
	return  - 1;
}



void board()
{

    system("cls");
    printf("\n\n\t\t\t\tКрестики Нолики\n\n");

    printf("\t\t\tИгрок 1 (X)  -  Игрок 2 (O)\n\n\n");


    printf("\t\t\t\t     |     |     \n");
    printf("\t\t\t\t  %c  |  %c  |  %c \n", kvadrat[1], kvadrat[2], kvadrat[3]);

    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");

    printf("\t\t\t\t  %c  |  %c  |  %c \n", kvadrat[4], kvadrat[5], kvadrat[6]);

    printf("\t\t\t\t_____|_____|_____\n");
    printf("\t\t\t\t     |     |     \n");

    printf("\t\t\t\t  %c  |  %c  |  %c \n", kvadrat[7], kvadrat[8], kvadrat[9]);

    printf("\t\t\t\t     |     |     \n\n");
}



