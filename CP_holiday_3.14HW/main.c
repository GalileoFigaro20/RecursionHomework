#include <stdio.h>

int N, nr = 0;

void print_Solution(int sol[N + 1][N + 1]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d\t", sol[i][j]);
        }
        printf("\n");
    }
    printf("-----------\n");
    nr++;
}

int can_be_placed(int i, int j, int sol[N + 1][N + 1]) {
    if (i >= 1 && i <= N && j >= 1 && j <= N && sol[i][j] == -1)
        return 1;
    return 0;
}

int bcktrck(int sol[N + 1][N + 1], int i, int j, int step_count, int *x_move, int *y_move) {
    if (step_count == N * N)
        print_Solution(sol);
    else {
        int k;
        for (k = 0; k < 8; k++) {
            int next_i = i + x_move[k];
            int next_j = j + y_move[k];

            if (can_be_placed(i + x_move[k], j + y_move[k], sol)) {
                sol[next_i][next_j] = step_count;
                if (bcktrck(sol, next_i, next_j, step_count + 1, x_move, y_move))
                    return 1;
                sol[i + x_move[k]][j + y_move[k]] = -1; // backtracking
            }
        }
    }
    return 0;
}

int backtracking() {
    int sol[N + 1][N + 1];

    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            sol[i][j] = -1;
        }
    }

    int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[1][1] = 0; // placing knight at cell(1, 1)

    if (bcktrck(sol, 1, 1, 1, x_move, y_move)) {
        return 1;
    }
    return 0;
}

int main() {
    printf("Input the number of rows and columns of the matrix:\n");
    scanf("%d", &N);
    printf("%d\n", backtracking());
    printf("%d", nr);
    return 0;
}
