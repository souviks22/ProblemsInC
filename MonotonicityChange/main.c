#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int polyVal(int *func, int degree, int x)
{
    int sum = 0;
    for (int i = 0; i <= degree; i++)
    {
        sum += func[i] * pow(x, i);
    }
    return sum;
}

int *differentiate(int *func, int degree)
{
    int *diff = (int *)malloc(sizeof(int) * (degree));
    for (int i = 0; i < degree; i++)
    {
        diff[i] = func[i + 1] * (i + 1);
    }
    return diff;
}

int searchForZero(int *func, int degree, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (polyVal(func, degree, mid) > 0)
    {
        return searchForZero(func, degree, mid + 1, end);
    }
    if (polyVal(func, degree, mid) < 0)
    {
        return searchForZero(func, degree, start, mid - 1);
    }
    return mid;
}

int pointOfChange(int *func, int degree)
{
    int *diff = differentiate(func, degree);
    int n = degree - 1;
    while (polyVal(diff, degree - 1, n) > 0)
    {
        n *= 2;
    }
    return searchForZero(diff, degree - 1, n / 2, n);
}

int main()
{
    printf("Enter the degree of the function - ");
    int degree;
    scanf("%d", &degree);
    int *func = (int *)malloc(sizeof(int) * (degree + 1));
    printf("Enter the coefficients in order of increasing power - ");
    for (int i = 0; i <= degree; i++)
    {
        scanf("%d", func + i);
    }

    printf("The function changes monotonicity at n = %d\n", pointOfChange(func, degree));

    return 0;
}