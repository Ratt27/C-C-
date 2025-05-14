#include <stdio.h>


void minheapify(int a[], int f, int size)
{
    int max = f, l = f * 2, r = f * 2 + 1, t;

    if (l <= size && a[l] > a[max])
        max = l;
    if (r <= size && a[r] > a[max])
        max = r;

    if (f != max)
    {
        t = a[f];
        a[f] = a[max];
        a[max] = t;
        minheapify(a, max, size);
    }
}

void minheap(int a[], int beg, int end)
{
    int i;
    for (i = end / 2; i >= beg; i--)
        minheapify(a, i, end);
}

void heapsort(int a[], int size)
{
    int i, t;

    for (i = size; i >= 2; i--)
    {
        t = a[1];
        a[1] = a[i];
        a[i] = t;
        minheapify(a, 1, i - 1);
    }
}

int main()
{
    int a[10], i;
    printf("Enter array elements:\n");

    for (i = 1; i <= 9; i++)
        scanf("%d", &a[i]);

    minheap(a, 1, 9);
    heapsort(a, 9);

    printf("\nSorted array:\n");

    for (i = 1; i <= 9; i++)
        printf("%4d", a[i]);

    return 0;
}
