//
// Created by Jeremi Toroj on 11/10/23.
//

#ifndef ZESTAW1_ARRAYSTACK_HPP
#define ZESTAW1_ARRAYSTACK_HPP

#include <stdexcept>

template <typename T>
class ArrayStack {
private:

    // vars
    T *data;
    int capacity;
    int top;

public:

    // constructor
    explicit ArrayStack(int cap = 1e6) {
        top = 0;
        capacity = cap;
        data = new T[capacity];
    }

    // removes the last added element
    T pop() {
        if (empty()) {
            throw std::out_of_range("ArrayStack is empty");
        } else {
            data[top] = T();
            return data[--top];
        }
    }

    // nodiscard attribute tells program that returned value should be used and creates a warning when it isnt
    // returns current size
    [[nodiscard]] int size() const {
        return top;
    }

    // adds new element on top
    void push(const T& x) {
        if (top == capacity) {
            throw std::out_of_range("ArrayStack is full.");
        } else {
            data[top] = x;
            top++;
        }
    }

    // returs true if stack is empty
    [[nodiscard]] bool empty() const {
        return (top == 0);
    }

    // frees memory
    ~ArrayStack() {
        delete[] data;
    }
};



#endif //ZESTAW1_ARRAYSTACK_HPP
