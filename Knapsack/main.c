#include <stdio.h>
#include <stdlib.h>

int maxProfit(int capacity, int weights[], int profits[], int length, int *dp)
{
    if (capacity == 0 || length == 0)
    {
        return 0;
    }
    if (dp[length - 1] != -1)
    {
        return dp[length - 1];
    }
    if (weights[length - 1] > capacity)
    {
        return maxProfit(capacity, weights, profits, length - 1, dp);
    }
    int case1 = profits[length - 1] + maxProfit(capacity - weights[length - 1], weights, profits, length - 1, dp);
    int case2 = maxProfit(capacity, weights, profits, length - 1, dp);
    dp[length - 1] = (case1 > case2) ? case1 : case2;
    return dp[length - 1];
}

int knapsack(int capacity, int weights[], int profits[], int length)
{
    int *dp = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        dp[i] = -1;
    }

    return maxProfit(capacity, weights, profits, length, dp);
}

int main()
{
    int c, n;
    printf("What is the maximum capacity? c = ");
    scanf("%d", &c);
    printf("How many elements to bag? n = ");
    scanf("%d", &n);

    int weights[n], profits[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight of element %d - ", i + 1);
        scanf("%d", weights + i);
        printf("Enter profit of element %d - ", i + 1);
        scanf("%d", profits + i);
    }

    printf("Maximum possible profit is %d\n", knapsack(c, weights, profits, n));

    return 0;
}