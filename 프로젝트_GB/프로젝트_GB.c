#include<stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH   30
#define HEIGHT  10
#define N_PLUS  5
#define N_MINUS 5

//#define WIDTH   10
//#define HEIGHT  7
//#define N_PLUS  15
//#define N_MINUS 15


// �迭 ���� �Լ��� �����ϴ� �͵� ������ �� ���� ���� ������ �θ� �������� ���� �ۼ��ϱ⵵ ���ϴ�.
// You can deliver array('board') through function parameters. 
// However, in this case, it's much readable to define 'board' and the other variables as global variables.
char board[HEIGHT][WIDTH];

// ������ ���� ��ġ
// the current position of the worm
int x;
int y;

// ���� ����(worm_x, worm_y�� ����/���ҷ�)
// the current direction. i.e. increment/decrement values for 'worm_x' and 'worm_y'
int dx;
int dy;

void initialize(int, int);
void display();
void turn();
void move();



// �����ǰ� ������ �ʱ�ȭ initialize game baord & earthworm
void initialize(int start_x, int start_y) {
    // ��, �Ʒ� ���κ� horizontal walls
    for (int i = 0; i < WIDTH; i++) {
        board[0][i] = board[HEIGHT - 1][i] = '#';
    }

    // ������ ���� inner space
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            board[i][j] = ' ';
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        board[i][0] = board[i][WIDTH - 8] = '#';
    }
    // ��, �� ���κ� vertical walls
    for (int i = 0; i < HEIGHT; i++) {
        board[i][0] = board[i][WIDTH - 1] = '#';
    }
    
    // ������ �ʱ� ��ġ�� ����
    // initial position & direction of earthworm
    x = start_x;
    y = start_y;
    dx = 0;
    dy = 1;
    board[x][y] = '@';
   
 
}

// ������ ȭ�� ��� display the game board
void display() {

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// ���� ���� �������� �� ĭ �̵�
void move() {
    board[x][y] = ' ';
    x += dx;
    y += dy;
    board[x][y] = '@';
}

int main(void)
{
    srand((unsigned int)time(NULL));

    initialize(1, 1);
    while (1) {
        move();
        system("cls");
        display();
        Sleep(500);
    }
    return 0;
}

