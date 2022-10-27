#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(int N)
{
	int num, guess, numofguess = 0;

	srand(time(NULL));

	num = rand() % N;

	printf("Угадай число от "
		" 1 до %d\n",
		N);
	do {

		if (numofguess > 10) {
			printf("\nТы проиграл! Всего у тебя 10 попыток!\n");
			break;
		}


		scanf("%d", &guess);


		if (guess > num)

		{
			printf("Меньше "
				"\n");
			numofguess++;
		}


		else if (num > guess)

		{
			printf("Больше"
				" \n");
			numofguess++;
		}

		else
			printf("Ты угадал"
				" число за %d "
				"попыток!\n",
				numofguess);

	} while (guess != num);
	system ("pause"); //Чтобы сразу не пропадало окно
}


int main_num_guess()
{
	int N = 100;
	guess(N);

	return 0;
}

