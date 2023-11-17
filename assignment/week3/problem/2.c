/*
* 프로그램 내용: 3주차 팀별과제 2번
* 개발자: 양혜성(202311419)
* 문제: 2차원 배열을 이용하여 tic-tac-toe 게임 프로그램을 작성하라. tic-tac-toe 게임 보드를 표현하는데 3×3의 이차원 배열을 이용한다. 2차원 배열의 원소가 0이면 아직 놓이지 않은 것이고 1이면 O을 2이면 ×를 표시한다고 가정한다
*/


#include <stdio.h>

#define SIZE 3

void printBoard(int board[SIZE][SIZE]) {            // 보드를 출력하는 함수
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf(" - ");
            else
                printf(" %c ", (board[i][j] == 1) ? 'O' : 'X');
        }
        printf("\n");
    }
    printf("\n");
}

int Win(int board[SIZE][SIZE], int player) {        // 승리 여부를 확인하는 함수
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;

    return 0;
}

int Draw(int board[SIZE][SIZE]) {       // 무승부 여부를 확인하는 함수
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int main() {
    int board[SIZE][SIZE] = { 0 };
    int player = 1, row, col, turn = 0;

    printf("틱택토 게임을 시작합니다.\n");

    do {            // 게임 루프
        printBoard(board);
        printf("플레이어 %c의 차례입니다. (행과 열을 선택하세요, 예: 1 2): ", (player == 1) ? 'O' : 'X');
        scanf("%d %d", &row, &col);

        if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != 0) {            // 입력한 위치가 유효한지 확인
            printf("잘못된 위치입니다. 다시 선택하세요.\n");
            continue;
        }

        board[row - 1][col - 1] = player;               // 선택한 위치에 마크 표시

        if (Win(board, player)) {               // 현재 플레이어가 이겼는지 확인
            printBoard(board);
            printf("플레이어 %c가 이겼습니다!\n", (player == 1) ? 'O' : 'X');
            break;
        }

        if (Draw(board)) {              // 무승부 확인
            printBoard(board);
            printf("무승부입니다!\n");
            break;
        }
        player = (player == 1) ? 2 : 1;             // 플레이어 변경
        turn++;
    } while (turn < SIZE * SIZE);
    return 0;
}





// cd /workspace/SeowonCProject/assignment/week3/problem/ && gcc ./2.c -o /tmp/a.out -lm && clear && /tmp/a.out