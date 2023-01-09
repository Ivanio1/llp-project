#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

#define H 30     //Высота игрового поля
#define W 60     //Ширина игрового поля
#define GHOSTS 5 //Количество врагов




void user_click();
void initialize();
void move_figures();
void show_playfield();
void set_cursor_position(int x, int y);
void fiil_ghosts();
void hidecursor();

int main_pacman();



