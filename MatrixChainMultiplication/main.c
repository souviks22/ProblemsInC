#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minMults(int *arr, int start, int end, int **dp, int **brackets)
{
    if (start == end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int currentMin = INT_MAX;
    for (int i = start; i < end; i++)
    {
        dp[start][i] = minMults(arr, start, i, dp, brackets);
        dp[i + 1][end] = minMults(arr, i + 1, end, dp, brackets);
        int provisionalMin = dp[start][i] + dp[i + 1][end] + arr[start - 1] * arr[i] * arr[end];
        if (provisionalMin < currentMin)
        {
            currentMin = provisionalMin;
            brackets[start][end] = i;
        }
    }
    return currentMin;
}

void minMultsOrder(int **brackets, int start, int end, char *c)
{
    if (start == end)
    {
        printf("%c", (*c)++);
        return;
    }
    printf("(");
    minMultsOrder(brackets, start, brackets[start][end], c);
    minMultsOrder(brackets, brackets[start][end] + 1, end, c);
    printf(")");
}

int main()
{
    printf("Size of order representation array - ");
    int n;
    scanf("%d", &n);
    int *orders = (int *)malloc(sizeof(int) * n);
    printf("Enter the array elements - ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", orders + i);
    }

    int **dp = (int **)malloc(sizeof(int *) * n);
    int **brackets = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * n);
        brackets[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = brackets[i][j] = -1;
        }
    }

    printf("Minimum number of element multiplications - %d\n", minMults(orders, 1, n - 1, dp, brackets));
    printf("Required order of multiplication - ");
    char *c = (char *)malloc(sizeof(char));
    *c = 'A';
    minMultsOrder(brackets, 1, n - 1, c);
    printf("\n");

    return 0;
}