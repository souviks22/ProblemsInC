#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int method0(int *A, int n)
{
    for (int a = 0; a < n; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            for (int c = b + 1; c < n; c++)
            {
                int ai, bi, ci;
                for (int i = 0; i < n; i++)
                {
                    if (A[i] == a)
                    {
                        ai = i;
                    }
                    else if (A[i] == b)
                    {
                        bi = i;
                    }
                    else if (A[i] == c)
                    {
                        ci = i;
                    }
                }
                if (ci < ai && ai < bi)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int method1(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (A[i] > A[j] && A[j] < A[k] && A[k] < A[i])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int method2(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        int lastLessNum = A[i];
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                if (A[j] > lastLessNum)
                {
                    return 0;
                }
                lastLessNum = A[j];
            }
        }
    }
    return 1;
}

int method3(int *A, int n)
{
    int lastMaxNum = 0, lastLessNum = n + 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > lastMaxNum)
        {
            lastMaxNum = A[i];
        }
        else
        {
            if (A[i] > lastLessNum)
            {
                return 0;
            }
            lastLessNum = A[i];
            while (i < n - 1 && A[i + 1] > lastMaxNum)
            {
                i++;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int n, *A;

    // scan the input
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        scanf(" %d", &A[i]);
    }
    printf("\n");
    printf("    Method 0: %s\n", method0(A, n) ? "Valid" : "Invalid");
    printf("    Method 1: %s\n", method1(A, n) ? "Valid" : "Invalid");
    printf("    Method 2: %s\n", method2(A, n) ? "Valid" : "Invalid");
    printf("    Method 3: %s\n", method3(A, n) ? "Valid" : "Invalid");

    exit(0);
}