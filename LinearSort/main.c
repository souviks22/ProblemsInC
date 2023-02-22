#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Array
{
    int *seq;
    int len;
    int low;
    int high;
} Array;

Array *generateArray()
{
    Array *a = (Array *)malloc(sizeof(Array));
    scanf("%d %d %d", &(a->low), &(a->high), &(a->len));
    a->seq = (int *)malloc(sizeof(int) * (a->len));
    srand(time(NULL));
    for (int i = 0; i < a->len; i++)
    {
        a->seq[i] = rand() % (a->high - a->low + 1) + a->low;
    }
    return a;
}

void sort(Array *a)
{
    int possibles = a->high - a->low + 1;
    int count[possibles + 1], aux[a->len];
    for (int i = 0; i < possibles + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < a->len; i++)
    {
        count[a->seq[i] - a->low + 1]++;
    }
    for (int i = 0; i < possibles; i++)
    {
        count[i + 1] += count[i];
    }
    for (int i = 0; i < a->len; i++)
    {
        aux[count[a->seq[i] - a->low]++] = a->seq[i];
    }
    for (int i = 0; i < a->len; i++)
    {
        a->seq[i] = aux[i];
    }
}

int main()
{
    Array *arr = generateArray();
    printf("\n");
    for (int i = 0; i < arr->len; i++)
    {
        printf("%d ", arr->seq[i]);
    }
    sort(arr);
    printf("\n\n");
    for (int i = 0; i < arr->len; i++)
    {
        printf("%d ", arr->seq[i]);
    }

    return 0;
}
