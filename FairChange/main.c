#include <stdio.h>
#include <stdlib.h>

int isAmountPossible(int amount, int i, int *coins, int *counts, int **dp)
{
    if (amount < 0 || i < 0 || counts[i] < 0)
    {
        return 0;
    }
    if (!amount)
    {
        return 1;
    }
    if (dp[i][amount] != -1)
    {
        return dp[i][amount];
    }
    counts[i]--;
    int take = isAmountPossible(amount - coins[i], i, coins, counts, dp);
    counts[i]++;
    int notTake = isAmountPossible(amount, i - 1, coins, counts, dp);
    return dp[i][amount] = take || notTake;
}

int main()
{
    printf("How many different coins are present? ");
    int n;
    scanf("%d", &n);

    int *coins = (int *)malloc(sizeof(int) * n);
    int *counts = (int *)malloc(sizeof(int) * n);
    printf("What are them and their frequency?\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", coins + i);
        scanf("%d", counts + i);
    }

    printf("What is the amount? ");
    int amount;
    scanf("%d", &amount);

    int **dp = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (amount + 1));
        for (int j = 0; j < amount + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    printf("The amount can%s be given\n", isAmountPossible(amount, n - 1, coins, counts, dp) ? "" : "not");

    return 0;
}