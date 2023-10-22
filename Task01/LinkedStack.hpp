#ifndef ZESTAW1_LINKEDSTACK_HPP
#define ZESTAW1_LINKEDSTACK_HPP

#include <stdexcept>

template <typename T>
class LinkedStack {

private:

    // struct with data holder of T type and pointer to next node
    struct Node {
        T data;
        Node* next;
    };

    // vars
    Node* top;
    int current_size;
    int capacity;

public:
    
    // explicit - constructor needs explicitly an int, it won't cast double to int
    // constructor
    explicit LinkedStack(int cap = 1e6) : top(nullptr), current_size(0), capacity(cap) {}

    // removes last added element
    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T val = top->data; 
        Node* temp = top;  // temp points to top
        top = top->next;   // top now points to previous element
        delete temp;      // freeing temp memory space which was top space
        current_size--;
        return val;
    }

    // returns current size
    [[nodiscard]] int size() const {
        return current_size;
    }

    // adds element - const making sure push doesnt change x, T& - doesnt make a copy of a T x; it refers to actual object
    void push(const T& x) {
        if (current_size == capacity) {
            throw std::out_of_range("Stack is full.");
        }
        Node* newNode = new Node;
        newNode->data = x;      // newNode now stores data x
        newNode->next = top;    // newNode now points to current top
        top = newNode;          // newNode now is new top
        current_size++;
    }
    
    // returns true if empty
    [[nodiscard]] bool empty() const {
        return (top == nullptr);
    }

    // frees memory - similar to pop but in loop
    ~LinkedStack() {
        while (!empty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

#endif //ZESTAW1_LINKEDSTACK_HPP
