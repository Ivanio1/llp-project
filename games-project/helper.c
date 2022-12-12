#include "helper.h"
#include <windows.h>
#include <stdlib.h>
int read_int() {
    printf("Введите число: \n");
    int x;
    scanf("%d", &x);
    return x;
}
