#include <stdio.h>

int getmax(int arr[], int size) {
    int max = arr[0], i;
    for (i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int size, int div) {
    int output[size];
    int count[10] = {0};
    int i;

    for (i = 0; i < size; i++)
        count[(arr[i] / div) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }
    for (i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int size) {
    int m, div;
    m = getmax(arr, size);
    for (div = 1; m / div > 0; div *= 10)
        countingSort(arr, size, div);
}

int main() {
    int size, i;
    printf("enter the size of the array \n");
    scanf("%d", &size);
    int arr[size];
    printf("enter the numbers in any order\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("before sorting :\n ");
    for (i = 0; i < size; i++)
        printf("%d", arr[i]);
    radixsort(arr, size);
    printf("\nafter sorting:\n");

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
