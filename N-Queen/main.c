#include <stdio.h>
#include <stdlib.h>

int isSafe(int **, int, int, int);
int isPlacedSafe(int **, int, int);

int main()
{
    printf("N = ");
    int N;
    scanf("%d", &N);

    int **nqueen = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        nqueen[i] = (int *)malloc(sizeof(int) * N);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            nqueen[i][j] = 0;
        }
    }

    if (isPlacedSafe(nqueen, N, 0))
    {
        printf("The placement of Queens should be like this\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", nqueen[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

int isSafe(int **arr, int n, int x, int y)
{
    for (int row = x - 1; row >= 0; row--)
    {
        if (arr[row][y] == 1)
        {
            return 0;
        }
    }
    for (int row = x - 1, col = y - 1; row >= 0 && col >= 0; row--, col--)
    {
        if (arr[row][col] == 1)
        {
            return 0;
        }
    }
    for (int row = x - 1, col = y + 1; row >= 0 && col < n; row--, col++)
    {
        if (arr[row][col] == 1)
        {
            return 0;
        }
    }
    return 1;
}

int isPlacedSafe(int **arr, int n, int x)
{
    if (x == n)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, n, x, i))
        {
            arr[x][i] = 1;
            if (isPlacedSafe(arr, n, x + 1))
            {
                return 1;
            }
            arr[x][i] = 0;
        }
    }
    return 0;
}