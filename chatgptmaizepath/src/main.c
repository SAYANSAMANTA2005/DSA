#include <stdio.h>
#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    {1, 0, 0, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1}
};

int sol[ROW][COL];

int isSafe(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1);
}

int solveMazeUtil(int x, int y) {
    if (x == ROW - 1 && y == COL - 1) {
        sol[x][y] = 1;
        return 1;
    }
    
    if (isSafe(x, y)) {
        sol[x][y] = 1;

        if (solveMazeUtil(x + 1, y) || solveMazeUtil(x, y + 1))
            return 1;

        sol[x][y] = 0;
        return 0;
    }
    
    return 0;
}

void solveMaze() {
    if (solveMazeUtil(0, 0)) {
        printf("Path Found:\n");
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++)
                printf("%d ", sol[i][j]);
            printf("\n");
        }
    } else {
        printf("No Path Found!\n");
    }
}

int main() {
    solveMaze();
    return 0;
}