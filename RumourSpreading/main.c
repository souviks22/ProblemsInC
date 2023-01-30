#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct
{
    double hi;
    double lo;
} two_val;

double hirec(int n)
{
    double hiArr[n + 1], loArr[n + 1];
    hiArr[0] = 1;
    loArr[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        hiArr[i] = 2 * hiArr[i - 1] + loArr[i - 1];
        loArr[i] = hiArr[i - 1] + loArr[i - 1];
    }
    return hiArr[n];
}

double lorec(int n)
{
    double hiArr[n + 1], loArr[n + 1];
    hiArr[0] = 1;
    loArr[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        hiArr[i] = 2 * hiArr[i - 1] + loArr[i - 1];
        loArr[i] = hiArr[i - 1] + loArr[i - 1];
    }
    return loArr[n];
}

two_val hilorec(int n)
{
    double hiArr[n + 1], loArr[n + 1];
    hiArr[0] = 1;
    loArr[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        hiArr[i] = 2 * hiArr[i - 1] + loArr[i - 1];
        loArr[i] = hiArr[i - 1] + loArr[i - 1];
    }
    two_val N;
    N.hi = hiArr[n];
    N.lo = loArr[n];
    return N;
}

two_val hiloformula(int n)
{
    two_val N;
    double root5 = sqrt(5);
    N.hi = ((5 + root5) / 10) * pow(((3 - root5) / 2), n + 1) + ((5 - root5) / 10) * pow(((3 + root5) / 2), n + 1);
    N.lo = ((-5 - 3 * root5) / 10) * pow(((3 - root5) / 2), n + 1) + ((-5 + 3 * root5) / 10) * pow(((3 + root5) / 2), n + 1);
    return N;
}

int main(int argc, char *argv[])
{
    two_val N1, N2, N3;
    int n;

    clock_t start, end;
    double cpu_time_used;

    scanf("%d", &n);
    printf("n = %d\n", n);

    printf("\n+++ Method 0\n");
    start = clock();
    N1.hi = hirec(n);
    N1.lo = lorec(n);
    end = clock();
    printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N1.hi, n, N1.lo);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Method 0 took %f seconds to execute \n", cpu_time_used);

    printf("\n+++ Method 1\n");
    start = clock();
    N2 = hilorec(n);
    end = clock();
    printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N2.hi, n, N2.lo);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Method 1 took %f seconds to execute \n", cpu_time_used);

    printf("\n+++ Method 2\n");
    start = clock();
    N3 = hiloformula(n);
    end = clock();
    printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N3.hi, n, N3.lo);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Method 2 took %f seconds to execute \n", cpu_time_used);

    exit(0);
}