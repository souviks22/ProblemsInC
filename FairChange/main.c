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

int possibleWays(int amount, int i, int *coins, int *counts, int **dp)
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
    int take = possibleWays(amount - coins[i], i, coins, counts, dp);
    counts[i]++;
    int notTake = possibleWays(amount, i - 1, coins, counts, dp);
    return dp[i][amount] = take + notTake;
}

int leastCoins(int amount, int i, int *coins, int *counts, int **dp)
{
    if (amount < 0 || i < 0 || counts[i] < 0)
    {
        return 1e9;
    }
    if (!amount)
    {
        return 0;
    }
    if (dp[i][amount] != -1)
    {
        return dp[i][amount];
    }
    counts[i]--;
    int take = 1 + leastCoins(amount - coins[i], i, coins, counts, dp);
    counts[i]++;
    int notTake = leastCoins(amount, i - 1, coins, counts, dp);
    return dp[i][amount] = (take < notTake) ? take : notTake;
}

int greatestCoins(int amount, int i, int *coins, int *counts, int **dp)
{
    if (amount < 0 || i < 0 || counts[i] < 0)
    {
        return -1e9;
    }
    if (!amount)
    {
        return 0;
    }
    if (dp[i][amount] != -1)
    {
        return dp[i][amount];
    }
    counts[i]--;
    int take = 1 + greatestCoins(amount - coins[i], i, coins, counts, dp);
    counts[i]++;
    int notTake = greatestCoins(amount, i - 1, coins, counts, dp);
    return dp[i][amount] = (take > notTake) ? take : notTake;
}

void reassignDp(int **dp, int n1, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            dp[i][j] = -1;
        }
    }
}

int main()
{
    int n = 5, amount = 50 - 17;
    int coins[] = {1, 2, 5, 10, 20}, counts[] = {4, 2, 2, 2, 1};

    // printf("How many different coins are present? ");
    // int n;
    // scanf("%d", &n);

    // int *coins = (int *)malloc(sizeof(int) * n);
    // int *counts = (int *)malloc(sizeof(int) * n);
    // printf("What are them and their frequency?\n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", coins + i);
    //     scanf("%d", counts + i);
    // }

    // printf("What is the amount? ");
    // int amount;
    // scanf("%d", &amount);

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
    reassignDp(dp, n, amount + 1);
    printf("There are %d ways to give back the change\n", possibleWays(amount, n - 1, coins, counts, dp));
    reassignDp(dp, n, amount + 1);
    printf("Least number of coins to give back the change is %d\n", leastCoins(amount, n - 1, coins, counts, dp));
    reassignDp(dp, n, amount + 1);
    printf("Greatest number of coins to give back the change is %d\n", greatestCoins(amount, n - 1, coins, counts, dp));

    return 0;
}