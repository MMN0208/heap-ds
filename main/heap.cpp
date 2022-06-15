#include "heap.h"
#include <iostream>
using namespace std;

template <class T>
Heap<T>::Heap() {
    this->array = NULL;
    this->count = 0;
    this->capacity = 10;
}

template <class T>
Heap<T>::~Heap() {
    delete this->array;
    this->count = 0;
    this->capacity = 0;
}

template <class T>
void Heap<T>::swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
    return;
}

template <class T>
void Heap<T>::ensureCapacity(int newCapacity) {
    T *temp = this->array;
    this->array = new T[newCapacity];
    for(int i = 0; i < this->count; i++) {
        this->array[i] = temp[i];
    }
    delete temp;
    return;
}

template <class T>
void Heap<T>::reheapUp(int position) {
    if(position > 0) {
        int parent = (position - 1) / 2;
        if(this->array[parent] < this->array[position]) {
            swap(&this->array[parent], &this->array[position]);
            reheapUp(parent);
        }
    }
    return;
}

template <class T>
void Heap<T>::reheapDown(int position) {
    int leftChild = position * 2 + 1;
    int rightChild = position * 2 + 2;
    int largeChild = position;
    if(leftChild < count) {
        if(rightChild < count && this->array[rightChild] > this->array[leftChild]) {
            largeChild = rightChild;
        }
        else largeChild = leftChild;
    }
    if(this->array[largeChild] > this->array[position]) {
        swap(&this->array[largeChild], &this->array[position]);
        reheapDown(largeChild);
    }
    return;
}

template <class T>
void Heap<T>::printHeap() {
    for(int i = 0; i < this->count; i++) {
        cout << this->array[i] << " ";
    }
    cout << endl;
}

template <class T>
void Heap<T>::insert(T data) {
    if(this->empty()) {
        this->array = new T[this->capacity];
        this->array[0] = data;
    }
    else {
        if(this->count == this->capacity) {
            int newCapacity = this->capacity * 3 / 2 + 1;
            this->ensureCapacity(newCapacity);
        }
        this->array[this->count] = data;
        reheapUp(this->count);
    }
    this->count++;
    return;
}

template <class T>
int Heap<T>::find(T data) {
    int found = -1;
    for(int i = 0; i < this->count && found == -1; i++) {
        if(this->array[i] == data) {
            found = i;
        }
    }
    return found;
}

template <class T>
bool Heap<T>::remove(T data) {
    int index = this->find(data);
    if(index > -1) {
        T temp = this->array[index];
        this->array[index] = this->array[count - 1];
        this->count--;
        if(this->array[index] > temp) {
            reheapUp(index);
        }
        else {
            reheapDown(index);
        }
        return true;
    }
    return false;
}

template <class T>
int Heap<T>::size() {
    return this->count;
}

template <class T>
bool Heap<T>::empty() {
    if(!this->count) {
        return true;
    }
    return false;
}

template class Heap<int>;
template class Heap<float>;
template class Heap<double>;