#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int polyVal(int *func, int degree, int n)
{
    int sum = 0;
    for (int i = 0; i <= degree; i++)
    {
        sum += func[i] * pow(n, i);
    }
    return sum;
}

int searchForPositive(int *func, int degree, int start, int end)
{
    if (start == end)
    {
        return start;
    }
    int mid = start + (end - start) / 2;
    if (polyVal(func, degree, mid) < 0)
    {
        return searchForPositive(func, degree, mid + 1, end);
    }
    if (polyVal(func, degree, mid) > 0)
    {
        return searchForPositive(func, degree, start, mid - 1);
    }
    return mid;
}

int findFirstPositive(int *func, int degree)
{
    int n = degree;
    while (polyVal(func, degree, n) < 0)
    {
        n *= 2;
    }
    if (n == degree)
    {
        return searchForPositive(func, degree, 0, n);
    }
    return searchForPositive(func, degree, n / 2, n);
}

int main()
{
    printf("Enter the degree of the monotonic increasing function - ");
    int degree;
    scanf("%d", &degree);
    int *func = (int *)malloc(sizeof(int) * (degree + 1));
    printf("Enter the coefficients in order of increasing power - ");
    for (int i = 0; i <= degree; i++)
    {
        scanf("%d", func + i);
    }

    printf("The function becomes positive first for n = %d\n", findFirstPositive(func, degree));

    return 0;
}