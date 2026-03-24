#include "ArrayQueue.hpp"


template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    maxSize = i;
    length = 0;
    frontIndex = 0;
    this->data = new T[maxSize];

}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data[(frontIndex + length - 1) % maxSize];

}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] this->data;
    this->data = nullptr;
    this->length = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    this->frontIndex = copyObj.frontIndex;
    this->data = new T[this->maxSize];
    for (int i = 0; i < this->length; ++i) {
        this->data[i] = copyObj.data[(this->frontIndex + i) % this->maxSize];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    frontIndex = (frontIndex + 1) % maxSize;
    --length;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {
        throw std::runtime_error("Queue is full");
    }
    data[(frontIndex + length) % maxSize] = elem;
    ++length;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
