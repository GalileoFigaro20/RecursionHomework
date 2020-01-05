#include <stdio.h>
int N, nr = 0;

void printSol(int sol[N+1][N+1])
{
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            printf("%d\t",sol[i][j]);
        }
        printf("\n");
    }
    printf("-----------\n");
    nr++;
}

int is_valid(int i, int j, int sol[N+1][N+1], int m[N+1][N+1]) {
    if (i>=1 && i<=N && j>=1 && j<=N && m[i][j]==1 && sol[i][j] == 0)
        return 1;
    return 0;
}

int knight_tour(int m[N+1][N+1], int sol[N+1][N+1], int i, int j, int counter, int x_move[], int y_move[]) {
    if (i == 1 || i == N || j == 1 || j == N)
    {
        printSol(sol);
    }else
    {
        int k;
        for(k=0; k<8; k++) {
            int i_next = i+x_move[k];
            int j_next = j+y_move[k];

            if(is_valid(i+x_move[k], j+y_move[k], sol, m)) {
                sol[i_next][j_next] = counter;
                if (knight_tour(m, sol, i_next, j_next, counter+1, x_move, y_move))
                    return 1;
                sol[i+x_move[k]][j+y_move[k]] = 0;
            }
        }
    }
    return 0;
}

int start_knight_tour(int k, int l) {
    int sol[N+1][N+1], m[N+1][N+1];;

    printf("Input the values of the matrix : (1 or 0)\n");
    int i, j;
    for(i=1; i<=N; i++) {
        for(j=1; j<=N; j++) {
            scanf("%d", &m[i][j]);
            sol[i][j] = 0;
        }
    }

    int x_move[] = {1, 0, -1, 0};
    int y_move[] = {0, -1, 0, 1};

    sol[k][l] = 1;
    if (knight_tour(m, sol, k, l, 2, x_move, y_move)) {
        return 1;
    }
    return 0;
}

int main()
{
    printf("Input the number of rows and collumns of the matrix:\n");
    scanf("%d", &N);
    getchar();
    int i,j;
    printf("Input the starting point :\n");
    scanf("%d %d", &i, &j);
    getchar();
    printf("%d\n",start_knight_tour(i, j));
    printf("%d", nr);
    return 0;
}
