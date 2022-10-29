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
    	printf("Вас приветствует Иван Соболев!\n");
    	printf("Наслаждайтесь игрой!\n\n\n");
        printf("Выберите игру \n");
         printf("1-Угадай число \n");
        printf("2-ВТ змейка \n");
        printf("3-КАЗИНО 777 \n");
        printf("4-Крестики нолики-мультиплеер \n");
        printf("5-ЯП пакман \n");

        printf("100-Выход \n" );

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
                printf("--Выход!--");
                _Exit(EXIT_SUCCESS);
    }
    system("cls");
    main();

}

int read_int() {
    printf("Введите число: \n");
    int x;
    scanf("%d", &x);
    return x;
}
