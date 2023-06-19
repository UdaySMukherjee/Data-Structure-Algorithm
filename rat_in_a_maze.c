#include <stdio.h>
#include <stdbool.h>
#define N 4

void print_solution(int sol[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

bool is_safe(int maze[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        return true;
    }
    return false;
}

bool solve_maze(int maze[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (is_safe(maze, x, y) == true) {
        sol[x][y] = 1;
        if (solve_maze(maze, x + 1, y, sol) == true) {
            return true;
        }
        if (solve_maze(maze, x, y + 1, sol) == true) {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if (solve_maze(maze, 0, 0, sol) == true) {
        printf("Solution exists:\n");
        print_solution(sol);
    } else {
        printf("Solution does not exist");
    }
    return 0;
}
