#include <stdio.h>

void toh3(int n, char from, char to, char aux)
{
    if (!n)
    {
        return;
    }
    toh3(n - 1, from, aux, to);
    printf("Disk is moved from %c to %c\n", from, to);
    toh3(n - 1, aux, to, from);
}

void toh4(int n, char from, char to, char aux1, char aux2)
{
    if (!n)
    {
        return;
    }
    int k = n / 2;
    toh4(k, from, aux1, to, aux2);
    toh3(n - k - 1, from, aux2, to);
    printf("Disk is moved from %c to %c\n", from, to);
    toh3(n - k - 1, aux2, to, from);
    toh4(k, aux1, to, from, aux2);
}

int main()
{
    int n;
    scanf("%d", &n);
    toh4(n, 'A', 'B', 'C', 'D');
    return 0;
}
