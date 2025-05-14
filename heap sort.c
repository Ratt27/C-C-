#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int i,j;
struct MinHeap {
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
};

struct MinHeap* createMinHeap(int cap) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->heap_size = cap;
    minHeap->capacity = cap;
    minHeap->harr = (int*)malloc(cap * sizeof(int));
    return minHeap;
}

void printArray(struct MinHeap* heap) {
	
    for ( i = 0; i < heap->heap_size; i++)
        printf("%d ", heap->harr[i]);
    printf("\n");
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

int getMin(struct MinHeap* heap) {
    return heap->harr[0];
}

void MinHeapify(struct MinHeap* heap, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap->heap_size && heap->harr[l] < heap->harr[i])
        smallest = l;
    if (r < heap->heap_size && heap->harr[r] < heap->harr[smallest])
        smallest = r;
    if (smallest != i) {
        int temp = heap->harr[i];
        heap->harr[i] = heap->harr[smallest];
        heap->harr[smallest] = temp;
        MinHeapify(heap, smallest);
    }
}

int extractMin(struct MinHeap* heap) {
    if (heap->heap_size <= 0)
        return INT_MAX;
    if (heap->heap_size == 1) {
        heap->heap_size--;
        return heap->harr[0];
    }

    int root = heap->harr[0];
    heap->harr[0] = heap->harr[heap->heap_size - 1];
    heap->heap_size--;
    MinHeapify(heap, 0);

    return root;
}

void getUnsortedArray(struct MinHeap* heap) {
    printf("Enter %d elements to sort using HEAPSORT\n", heap->capacity);
    for (i = 0; i < heap->capacity; i++)
        scanf("%d", &heap->harr[i]);
}

void heapSort(struct MinHeap* heap) {
    int temp[heap->capacity];
    for (j = 0; j < heap->capacity; j++) {
        temp[j] = extractMin(heap);
        printf("%d ", temp[j]);
    }
}

int main() {
    int size;
    printf("Enter Size of Min Heap\n");
    scanf("%d", &size);

    struct MinHeap* obj = createMinHeap(size);
    getUnsortedArray(obj);

    printf("Unsorted Array :\n");
    printArray(obj);

    for ( i = size / 2 - 1; i >= 0; i--) {
        MinHeapify(obj, i);
    }

    printf("Heap Sorted Array :\n");
    heapSort(obj);

    free(obj->harr);
    free(obj);

    return 0;
}
