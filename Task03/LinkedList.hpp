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
        T data;         // data
        Node* next;     // next Node
        Node* prev;     // previous Node

        // default constructor
        Node() : data(T()), next(nullptr), prev(nullptr) {}

        // copy constructor
        explicit Node(const T& aug) : data(aug), next(nullptr), prev(nullptr) {}

        // move constructor
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

        // pre-increment
        Iterator operator++() {
            currentNode = currentNode->next;
            return *this;
        }

        // pre-decrement
        Iterator operator--() {
            currentNode = currentNode->prev;
            return *this;
        }

        // post-increment
        Iterator operator++(int) {
            Node *helper = currentNode;
            currentNode = currentNode->next;
            return Iterator{helper};
        }

        // post-decrement
        Iterator operator--(int) {
            Node *helper = currentNode;
            currentNode = currentNode->prev;
            return Iterator{helper};
        }

        // returns reference to data held by Node pointer by iterator
        T& operator*(){
            return currentNode->data;
        }

        // checks if Nodes that two iterators are pointing to are equal
        bool operator==(const Iterator& other ){
            return currentNode == other.currentNode;
        }

        // opposite UP
        bool operator!=(const Iterator& other ){
            return !(currentNode == other.currentNode);
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
// ################################## Constructor ######################################

// ################################## Basic methods ######################################
    int size(){
        return current_size;
    }

    bool empty(){
        return current_size == 0;
    }
// ################################## Basic methods ######################################

// ################################## Iterator Methods ######################################

    // returns iterator pointing at first element
    Iterator begin(){
        return Iterator{ guard->next };
    }

    // returns iterator pointing at guard
    Iterator end(){
        return Iterator{ guard };
    }

    // adds Node before Node that it is pointing to
    template<class U>
    Iterator insert( Iterator it, U&& x ){

        // creates newNode
        Node* newNode = new Node(std::forward<U>(x));

        // if list is empty creates first Node
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

    // finds first Node storing data x
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
// ################################## Iterator Methods ######################################


// ################################## List Methods ######################################


    // adds Node to the front of the list
    template < class U >
    void push_front( U&& x ){
        if( size() == capacity ){
            throw std::out_of_range("Overflow - capacity reached.");
        }

        insert(begin(), std::forward<U>(x));
    }

    // removes first element of the list and returns its data
    T pop_front(){
        if( empty() ){
            throw std::out_of_range("Underflow - list is empty.");
        }

        T val = guard->next->data;      // stores first Node's data
        erase(begin());              // removes first Node
        return val;                     // returns its data
    }

    // adds new Node at the end of list
    template < class U >
    void push_back( U&& x ){
        if( size() == capacity ){
            throw std::out_of_range("Overflow - capacity reached.");
        }

        insert(end(), std::forward<U>(x));
    }

    // removes last node and returns its data
    T pop_back(){
        if( empty() ){
            throw std::out_of_range("Underflow - list is empty.");
        }

        T val = guard->prev->data;             // saves data
        erase(Iterator{guard->prev});       // deletes last Node
        return val;                            // returns val of last Node
    }

    // removes all Nodes(x) and returns number of Nodes which stored x
    int remove(const T& x){
        if( empty() ){
            throw std::out_of_range("Underflow - list is empty.");
        }

        int result = 0;             // counter
        Iterator it = begin();      // iterator = gourd->next

        while( it != end() ){
            if( it->data == x ){
                result++;
                erase(it);
                current_size--;
            }
            else
                it++;           // if I always increment it erase() is gonna cause skipping of element

        }

        return result;
    }

    // finds Node which stored data == x and erases Node with x then creates newNode in place of it storing y
    template<class U>
    bool replace(const T& x, U&& y)
    {
        Iterator firstX = find(x);  // finds first Node with x

        if(firstX != end())         // checking for success
        {
            insert(erase(firstX), std::forward<U>(y));  // erase old Node(x), insert Node(y) in its place
            return true;
        }

        // element wasn't found
        return false;
    }

    // deletes all nodes till guard
    void clear(){

        Iterator it = begin();

        while(it != end()){
            it = erase(it);
        }

    }
// ################################## List Methods ######################################


// ################################## Destructor ######################################

    ~LinkedList(){
        clear();
        delete guard;
    }

private:

    Node* guard;        // pointer to guard Node which stores pointers to first and last element
    int current_size;   // current size of list
    int capacity;       // max list capacity

};




#endif //ZESTAW3_LINKEDLIST_HPP
