#pragma once

#include <iostream>

using namespace std;

template<typename T>
class MyVector {
private:
    T* arr = nullptr;
    size_t cap;
    size_t elems;
    const int default_capacity = 1;
public:
    MyVector() {
        arr = new T[default_capacity];
        cap = default_capacity;
        elems = 0;
    };
    void push_back(const T& data);
    void pop_back();
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    T& operator[](size_t pos);
    void print() const;
    ~MyVector();
};

template<typename T>
MyVector<T>::~MyVector() {
    delete[] arr;
}

template<typename T>
void MyVector<T>::push_back(const T& data) {
    if (elems < cap) {
        *(arr + elems) = data;
        elems++;
    }
    else {
        auto tmp_arr = new T[cap * 2];
        cap *= 2;
        for (int i = 0; i < elems; i++) {
            tmp_arr[i] = arr[i];
        }
        delete[] arr;
        arr = tmp_arr;
        *(arr + elems) = data;
        elems++;
    }
}

template<typename T>
T& MyVector<T>::operator[](size_t pos) {
    if (pos >= 0 && pos <= elems)
        return *(this->arr + pos);
    throw std::out_of_range("Out of bounds element access");
}

template<typename T>
size_t MyVector<T>::size() const {
    return elems;
}

template<typename T>
size_t MyVector<T>::capacity() const {
    return cap;
}

template<typename T>
void MyVector<T>::pop_back() {
    if (empty()) {
        return;
    }
    elems--;
}

template<typename T>
bool MyVector<T>::empty() const {
    return elems == 0;
}

template<typename T>
void MyVector<T>::print() const {
    for (int i = 0; i < elems; i++) {
        std::cout << this->arr[i] << " ";
    }
}