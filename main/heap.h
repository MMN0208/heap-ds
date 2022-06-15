#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap {
    T *array;
    int count;
    int capacity;
    void swap(T *a, T *b);
    void reheapUp(int position);
    void reheapDown(int position);
    void ensureCapacity(int newCapacity);
public:
    Heap();
    ~Heap();
    void printHeap();
    void insert(T data);
    int find(T data);
    bool remove(T data);
    int size();
    bool empty();
};

#endif