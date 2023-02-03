#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int n, int toFind, int lo, int hi)
{
    if (lo > hi)
    {
        return -1;
    }
    int mid = lo + (hi - lo) / 2;
    if (toFind < arr[mid])
    {
        return binarySearch(arr, n, toFind, lo, mid - 1);
    }
    if (toFind > arr[mid])
    {
        return binarySearch(arr, n, toFind, mid + 1, hi);
    }
    return mid;
}

int findRotation(int *arr, int n, int lo, int hi)
{
    int mid = lo + (hi - lo) / 2;
    if (mid == lo)
    {
        return hi;
    }
    if (arr[lo] > arr[mid])
    {
        return findRotation(arr, n, lo, mid);
    }
    if (arr[hi] < arr[mid])
    {
        return findRotation(arr, n, mid, hi);
    }
    return -1;
}

int findElement(int *arr, int n, int toFind)
{
    int pivot = findRotation(arr, n, 0, n - 1);
    if (pivot == -1)
    {
        return binarySearch(arr, n, toFind, 0, n - 1);
    }
    int index = binarySearch(arr, n, toFind, 0, pivot - 1);
    if (index == -1)
    {
        return binarySearch(arr, n, toFind, pivot, n - 1);
    }
    return index;
}

int main()
{
    printf("Give the size of the rotated sorted array - ");
    int N;
    scanf("%d", &N);
    int *rotatedSortedArr = (int *)malloc(sizeof(int) * N);
    printf("Give the elements of the array in order - ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", rotatedSortedArr + i);
    }
    printf("Give the element to search for - ");
    int target;
    scanf("%d", &target);

    int index = findElement(rotatedSortedArr, N, target);
    if (index == -1)
    {
        printf("The element is not found\n");
    }
    else
    {
        printf("The element is found at index %d\n", index);
    }

    return 0;
}
