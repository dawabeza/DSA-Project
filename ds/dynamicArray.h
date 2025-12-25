#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int currentSize;

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() : data(nullptr), capacity(0), currentSize(0) {}

    // Copy constructor (deep copy)
    DynamicArray(const DynamicArray& other)
        : data(nullptr), capacity(0), currentSize(0) {
        if (other.capacity > 0) {
            capacity = other.capacity;
            currentSize = other.currentSize;
            data = new T[capacity];
            for (int i = 0; i < currentSize; ++i) data[i] = other.data[i];
        }
    }

    // Copy assignment (deep copy)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;
        delete[] data;
        data = nullptr;
        capacity = 0;
        currentSize = 0;
        if (other.capacity > 0) {
            capacity = other.capacity;
            currentSize = other.currentSize;
            data = new T[capacity];
            for (int i = 0; i < currentSize; ++i) data[i] = other.data[i];
        }
        return *this;
    }

    // Move constructor
    DynamicArray(DynamicArray&& other) noexcept
        : data(other.data), capacity(other.capacity), currentSize(other.currentSize) {
        other.data = nullptr;
        other.capacity = 0;
        other.currentSize = 0;
    }

    // Move assignment
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) return *this;
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        currentSize = other.currentSize;
        other.data = nullptr;
        other.capacity = 0;
        other.currentSize = 0;
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(T value) {
        if (currentSize == capacity) {
            resize();
        }
        data[currentSize++] = value;
    }

    // --- The missing removeAt method ---
    void removeAt(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }

        // Shift all elements to the left to fill the gap
        for (int i = index; i < currentSize - 1; i++) {
            data[i] = data[i + 1];
        }
        currentSize--;
    }

    int size() const { return currentSize; }

    void clear() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        currentSize = 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= currentSize) throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    // Iterator Support
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + currentSize; }
    const T* end() const { return data + currentSize; }
};

#endif