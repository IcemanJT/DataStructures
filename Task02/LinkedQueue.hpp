//
// Created by Jeremi Toroj on 22.10.23.
//

#ifndef ZESTAW2_LINKEDQUEUE_HPP
#define ZESTAW2_LINKEDQUEUE_HPP


#include <stdexcept>

template<typename T, int N>
class LinkedQueue{
private:

    // Node struct of
    struct Node {
        explicit Node(const T& aug): data{aug}, next{nullptr} {};

        T data;
        Node* next;
    };

    Node* front;        // pointer to first node
    Node* end;          // pointer to last node
    int currect_size;
    int capacity;

public:

    // constructor
    LinkedQueue(){
        currect_size = 0;
        capacity = N;
        front = nullptr;
        end = nullptr;
    }

    // checks if queue is empty
    bool empty(){
        return currect_size==0;
    }

    // returns current size fo queue
    int size(){
        return currect_size;
    }

    // returns referance to first element
    T& front_ref(){
        if (empty()){
            throw std::out_of_range("Underflow - queue is empty.");
        }

        return front->data;
    }

    // removes first element in queue
    T pop(){
        if (empty()){
            throw std::out_of_range("Underflow - queue is empty.");
        }

        currect_size--;
        T val = front->data;    // stores value of first element
        Node *temp = front;     // pointer pointaing at same node as front
        front = front->next;    // front now points to 2nd element
        delete temp;            // frees memeory where front node was located
        return val;
    }


    // perfect forwarding and universal referance in ArrayQueue.hpp comments
    template<class U>
    void push(U&& aug){
        if (size() == capacity){
            throw std::out_of_range("Underflow - queue is empty.");
        }

        // creates new node
        // calls constructor which initializes Node to data = aug and next=nullptr
        Node *newNode = new Node(std::forward<U>(aug));

        // if queue is empty newNode is assigned to front and end pointers
        if (empty()){
            end = newNode;
            front = newNode;
        }   // else only end Node in changed - adding to the end
        else {
            end->next = newNode;
            end = newNode;
        }
        currect_size++;
    }

    // destructor - freeing space till all Nodes are deleted
    ~LinkedQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};


#endif //ZESTAW2_LINKEDQUEUE_HPP
