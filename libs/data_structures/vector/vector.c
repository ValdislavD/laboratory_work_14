#include <stdint.h>
#include <malloc.h>
#include "vector.h"

static void badAllocV() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(size_t n) {
    int *v = (int *) malloc(sizeof(int) * n);
    if (v == NULL) {
        badAllocV();
    }
    return (vector) {v, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        return;
    }
    else if (newCapacity < v->size) {
        v->size = newCapacity;
    }
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    v->capacity = newCapacity;
    if (v->data == NULL) {
        badAllocV();
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    reserve(v, 0);
}
