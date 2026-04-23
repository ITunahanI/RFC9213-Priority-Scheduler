#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "priority_utils.h"

typedef struct {
    HttpRequest** data;
    int size;
    int capacity;
} MinHeap;

MinHeap* create_heap(int capacity);
void insert_request(MinHeap* heap, HttpRequest* req);
HttpRequest* extract_min(MinHeap* heap);
void free_heap(MinHeap* heap);

#endif
