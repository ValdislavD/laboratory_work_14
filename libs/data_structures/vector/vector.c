#include <stdio.h>
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void append_(int *data, int *size, int x) {
    data[*size] = x; // Добавляем новый элемент в конец массива данных
    (*size)++;       // Увеличиваем размер массива
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    append_(v->data, &v->size, x);
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        badAllocV();
    }
    v->size--;
}
