#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(int N)
{
	int num, guess, numofguess = 0;

	srand(time(NULL));

	num = rand() % N;

	printf("������ ����� �� "
		" 1 �� %d\n",
		N);
	do {

		if (numofguess > 10) {
			printf("\n�� ��������! ����� � ���� 10 �������!\n");
			break;
		}


		scanf("%d", &guess);


		if (guess > num)

		{
			printf("������ "
				"\n");
			numofguess++;
		}


		else if (num > guess)

		{
			printf("������"
				" \n");
			numofguess++;
		}

		else
			printf("�� ������"
				" ����� �� %d "
				"�������!\n",
				numofguess);

	} while (guess != num);
	system ("pause"); //����� ����� �� ��������� ����
}


int main_num_guess()
{
	int N = 100;
	guess(N);

	return 0;
}

