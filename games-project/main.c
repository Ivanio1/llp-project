#include "snake.h"
#include "casino.h"
#include "pacman.h"
#include "krestics_and_noliks.h"
#include "number_guess.h"
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
void main()
{
    	setlocale(LC_ALL,"Russian");
    	printf("��� ������������ ���� �������!\n");
    	printf("������������� �����!\n\n\n");
        printf("�������� ���� \n");
         printf("1-������ ����� \n");
        printf("2-�� ������ \n");
        printf("3-������ 777 \n");
        printf("4-�������� ������-����������� \n");
        printf("5-�� ������ \n");

        printf("100-����� \n" );

    int n = read_int();
    if(n==5){
         main_pacman();
    }
    if(n==2){
         main_snake();
    }
    if(n==3){
        main_casino();
    }
    if(n==4){
        main_kandn();
    }
    if(n==1){
        main_num_guess();
    }


     if(n==100){
                printf("--�����!--");
                _Exit(EXIT_SUCCESS);
    }
    system("cls");
    main();

}

int read_int() {
    printf("������� �����: \n");
    int x;
    scanf("%d", &x);
    return x;
}
