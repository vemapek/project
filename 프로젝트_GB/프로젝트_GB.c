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


// 배열 등을 함수에 전달하는 것도 좋지만 이 경우는 전역 변수로 두면 가독성도 높고 작성하기도 편하다.
// You can deliver array('board') through function parameters. 
// However, in this case, it's much readable to define 'board' and the other variables as global variables.
char board[HEIGHT][WIDTH];

// 지렁이 현재 위치
// the current position of the worm
int x;
int y;

// 현재 방향(worm_x, worm_y의 증가/감소량)
// the current direction. i.e. increment/decrement values for 'worm_x' and 'worm_y'
int dx;
int dy;

void initialize(int, int);
void display();
void turn();
void move();



// 게임판과 지렁이 초기화 initialize game baord & earthworm
void initialize(int start_x, int start_y) {
    // 위, 아래 가로벽 horizontal walls
    for (int i = 0; i < WIDTH; i++) {
        board[0][i] = board[HEIGHT - 1][i] = '#';
    }

    // 안쪽의 공백 inner space
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            board[i][j] = ' ';
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        board[i][0] = board[i][WIDTH - 8] = '#';
    }
    // 좌, 우 세로벽 vertical walls
    for (int i = 0; i < HEIGHT; i++) {
        board[i][0] = board[i][WIDTH - 1] = '#';
    }
    
    // 지렁이 초기 위치와 방향
    // initial position & direction of earthworm
    x = start_x;
    y = start_y;
    dx = 0;
    dy = 1;
    board[x][y] = '@';
   
 
}

// 게임판 화면 출력 display the game board
void display() {

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// 현재 진행 방향으로 한 칸 이동
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

