//
// Created by Jeremi Toroj on 01.11.23.
//

#ifndef ZESTAW3_LINKEDLIST_HPP
#define ZESTAW3_LINKEDLIST_HPP


#include <iostream>

template<class T>
class LinkedList{

public:

// ################################## Node Class ######################################
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node() : data(T()), next(nullptr), prev(nullptr) {}

        explicit Node(const T& aug) : data(aug), next(nullptr), prev(nullptr) {}

        explicit Node(T&& aug) : data(aug), next(nullptr), prev(nullptr) {}

        /*

        template <typename U>
        explicit Node( U&& aug ): data{aug}, next{nullptr}, prev{nullptr} {};

        Clang-Tidy: Constructor accepting a forwarding reference can hide the copy and move constructors

         */


    };
// ################################## Node Class ######################################


// ################################## Iterator Class ######################################
    struct Iterator{

        Node* currentNode;

        // constructor
        explicit Iterator( Node *ptr = nullptr ): currentNode{ptr} {};

        T* operator->() {
            return &(currentNode->data);
        }

        Iterator operator++() {
            currentNode = currentNode->next;
            return *this;
        }

        Iterator operator--() {
            currentNode = currentNode->prev;
            return *this;
        }

        T& operator*(){
            return currentNode->data;
        }

        bool operator==(const Iterator& other ){
            return currentNode == other.currentNode;
        }

        bool operator!=(const Iterator& other ){
            return !(currentNode == other.currentNode);
        }

        Iterator operator++(int) {
            Node *helper = currentNode;
            currentNode = currentNode->next;
            return Iterator{helper};
        }

        Iterator operator--(int) {
            Node *helper = currentNode;
            currentNode = currentNode->prev;
            return Iterator{helper};
        }

    };
// ################################## Iterator Class ######################################



// ################################## Constructor ######################################
    explicit LinkedList(int cap = 1000){
        capacity = cap;
        current_size = 0;
        guard = new Node();
        guard->next = guard;
        guard->prev = guard;
    }


// ################################## Basic methods ######################################
    int size(){
        return current_size;
    }

    bool empty(){
        return current_size == 0;
    }

// ################################## Iterator Methods ######################################


    Iterator begin(){
        return Iterator{ guard->next };
    }

    Iterator end(){
        return Iterator{ guard };
    }

    template<class U>
    Iterator insert( Iterator it, U&& x ){

        Node* newNode = new Node(std::forward<U>(x));

        if( current_size == 0 ){

            guard->next = newNode;
            guard->prev = newNode;
            newNode->prev = guard;
            newNode->next = guard;

        }
        else {

            newNode->prev = it.currentNode->prev;   // newNode->prev now points at element behind it
            newNode->next = it.currentNode;         // newNode->next now points at it
            it.currentNode->prev = newNode;         // changed current Node->prev to new node
            newNode->prev->next = newNode;

        }
        ++current_size;
        return Iterator{newNode};
    }

    Iterator erase(Iterator it){

        Iterator toReturn = Iterator{it.currentNode->next};

        it.currentNode->next->prev = it.currentNode->prev;
        it.currentNode->prev->next = it.currentNode->next;

        delete it.currentNode;
        current_size--;
        return toReturn;

    }

    Iterator find(const T& x){
        Iterator it = begin();

        while( it != end() ){
            if( it.currentNode->data == x ){
                return it;
            }
            it++;
        }

        return it;
    }

// ################################## List Methods ######################################

    template < class U >
    void push_front( U&& x ){
        if( size() == capacity ){
            throw std::out_of_range("Overflow - capacity reached.");
        }

        insert(begin(), std::forward<U>(x));
    }

    T pop_front(){
        if( empty() ){
            throw std::out_of_range("Underflow - list is empty.");
        }

        T val = guard->next->data;
        erase(begin());
        return val;
    }

    template < class U >
    void push_back( U&& x ){
        if( size() == capacity ){
            throw std::out_of_range("Overflow - capacity reached.");
        }

        insert(end(), std::forward<U>(x));
    }

    T pop_back(){
        if( empty() ){
            throw std::out_of_range("Underflow - list is empty.");
        }

        T val = guard->prev->data;
        erase(Iterator{guard->prev});
        return val;
    }

    int remove(const T& x){
        if( empty() ){
            throw std::out_of_range("Underflow - list is empty.");
        }

        int result = 0;
        Iterator it = begin();

        while( it != end() ){
            if( it->data == x ){
                result++;
                erase(it);
                current_size--;
            }
            else
                it++;           // if I always increment erase() is gonna cause skipping of element

        }

        return result;
    }

    template<class U>
    bool replace(const T& x, U&& y)
    {
        Iterator firstX = find(x);

        if(firstX != end())
        {
            insert(erase(firstX), std::forward<U>(y));
            return true;
        }
        return false;
    }


    void clear(){

        Iterator it = begin();

        while(it != end()){
            it = erase(it);
        }

    }

// ################################## Destructor ######################################

    ~LinkedList(){
        clear();
        delete guard;
    }

private:

    Node* guard;
    int current_size;
    int capacity;

};




#endif //ZESTAW3_LINKEDLIST_HPP
