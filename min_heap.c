#include "min_heap.h"
#include <stdlib.h>

MinHeap* create_heap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->data = (HttpRequest**)malloc(capacity * sizeof(HttpRequest*));
    return heap;
}

void swap(HttpRequest** a, HttpRequest** b) {
    HttpRequest* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(MinHeap* heap, int index) {
    while (index > 0 && heap->data[(index - 1) / 2]->urgency > heap->data[index]->urgency) {
        swap(&heap->data[(index - 1) / 2], &heap->data[index]);
        index = (index - 1) / 2;
    }
}

void heapify_down(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left]->urgency < heap->data[smallest]->urgency)
        smallest = left;
    if (right < heap->size && heap->data[right]->urgency < heap->data[smallest]->urgency)
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapify_down(heap, smallest);
    }
}

void insert_request(MinHeap* heap, HttpRequest* req) {
    if (heap->size == heap->capacity) return;
    heap->data[heap->size] = req;
    heapify_up(heap, heap->size);
    heap->size++;
}

HttpRequest* extract_min(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    HttpRequest* min_req = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);
    return min_req;
}

void free_heap(MinHeap* heap) {
    for(int i=0; i < heap->size; i++) free(heap->data[i]);
    free(heap->data);
    free(heap);
}
