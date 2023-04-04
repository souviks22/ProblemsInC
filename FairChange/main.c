#include <stdio.h>
#include <stdlib.h>

int isPossible(int amount, int i, int coins[], int count[], int **dp)
{
    if (!amount)
    {
        return 1;
    }
    if (!i)
    {
        return (!(amount % coins[i]) && (amount / coins[i] <= count[i])) ? 1 : 0;
    }
    if (dp[amount][i] != -1)
    {
        return dp[amount][i];
    }
    int n = (amount / coins[i] > count[i]) ? count[i] : amount / coins[i];
    dp[amount][i] = isPossible(amount - coins[i] * n, i - 1, coins, count, dp);
    return dp[amount][i];
}

int main()
{
    int amount = 50 - 17, n = 5;
    int coins[] = {1, 2, 5, 10, 20}, count[] = {4, 2, 2, 2, 1};

    int **dp = (int **)malloc(sizeof(int *) * (amount + 1));
    for (int i = 0; i < amount + 1; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    if (isPossible(amount, n - 1, coins, count, dp))
    {
        printf("possible\n");
    }
    else
    {
        printf("not possible\n");
    }

    return 0;
}