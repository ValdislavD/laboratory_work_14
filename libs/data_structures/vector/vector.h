#ifndef UNTITLED17_VECTOR_H
#define UNTITLED17_VECTOR_H

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти на newCapacity,
// выделенное под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из вектора v,
// но не освобождает выделенную память
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору v
void deleteVector(vector *v);

#endif //UNTITLED17_VECTOR_H
