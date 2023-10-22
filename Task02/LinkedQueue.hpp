//
// Created by Jeremi Toroj on 22.10.23.
//

#ifndef ZESTAW2_LINKEDQUEUE_HPP
#define ZESTAW2_LINKEDQUEUE_HPP


#include <stdexcept>

template<typename T, int N>
class LinkedQueue{
private:

    struct Node {
        explicit Node(const T& aug): data{aug}, next{nullptr} {};

        T data;
        Node* next;
    };

    Node* front;
    Node* end;
    int currect_size;
    int capacity;

public:

    LinkedQueue(){
        currect_size = 0;
        capacity = N;
        front = nullptr;
        end = nullptr;
    }

    bool empty(){
        return currect_size==0;
    }

    int size(){
        return currect_size;
    }

    T& front_ref(){
        if (empty()){
            throw std::out_of_range("Underflow - queue is empty.");
        }

        return front->data;
    }

    T pop(){
        if (empty()){
            throw std::out_of_range("Underflow - queue is empty.");
        }

        currect_size--;
        T val = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        return val;
    }

    template<class U>
    void push(U&& aug){
        if(size() == capacity){
            throw std::out_of_range("Underflow - queue is empty.");
        }

        Node *newNode = new Node(std::forward<U>(aug));

        if(size() == 0){
            end = newNode;
            front = newNode;
        }
        else{
            end->next = newNode;
            end = newNode;
        }
        currect_size++;
    }

    ~LinkedQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};


#endif //ZESTAW2_LINKEDQUEUE_HPP
