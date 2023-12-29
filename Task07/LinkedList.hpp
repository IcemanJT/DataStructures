// Creator: Jeremi Toroj
// Date: 29.12.2023

#ifndef ZESTAW3_LINKEDLIST_HPP
#define ZESTAW3_LINKEDLIST_HPP

#include <iostream>
#include <algorithm>
#include <utility>

template<class K, class V>
using Pair = std::pair<K, V>;

template<class K, class V>
class LinkedList {
private:
    // ################################## Node Class ######################################

    struct Node {
        Pair<K, V> data; // data
        Node *next;           // next Node
        Node *prev;           // previous Node

        // default constructor
        Node() : data(std::make_pair(K(), V())), next(nullptr), prev(nullptr) {}

        // copy constructor
        explicit Node(const Pair<K, V> &aug) : data(aug), next(nullptr), prev(nullptr) {}

        // move constructor
        explicit Node(Pair<K, V> &&aug) : data(std::move(aug)), next(nullptr), prev(nullptr) {}
    };

    // ################################## Node Class ######################################


    // ################################## Vars ######################################

    int capacity;       // max list capacity
    int current_size;   // current size of list
    Node *guard;        // pointer to guard Node which stores pointers to the first and last element

    // ################################## Vars ######################################

public:


    // ################################## Iterator Class ######################################

    struct Iterator {

        Node *currentNode;

        // constructor
        explicit Iterator(Node *ptr = nullptr) : currentNode{ptr} {}

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
        Pair<K, V> &operator*() {
            return currentNode->data;
        }

        // checks if Nodes that two iterators are pointing to are equal
        bool operator==(const Iterator &other) {
            return currentNode == other.currentNode;
        }

        // opposite UP
        bool operator!=(const Iterator &other) {
            return !(currentNode == other.currentNode);
        }

    };

    // ################################## Iterator Class ######################################


    // ################################## Constructors ######################################

    // default constructor
    explicit LinkedList(int cap = 1000) : capacity(cap), current_size(0) {
        guard = new Node();
        guard->next = guard;
        guard->prev = guard;
    }

    // Copy constructor
    LinkedList(const LinkedList &other) : capacity(other.capacity), current_size(0) {
        guard = new Node();
        guard->next = guard;
        guard->prev = guard;

        // Copy elements from the other list to this list
        for (const auto &element : other) {
            push_back(element);
        }
    }

    // Move constructor
    LinkedList(LinkedList &&other) noexcept : capacity(other.capacity), current_size(other.current_size), guard(other.guard) {
        // Reset the other list
        other.capacity = 0;
        other.current_size = 0;
        other.guard = nullptr;
    }

    // ################################## Constructors ######################################


    // ################################## Operators ######################################

    // Copy assignment operator
    LinkedList &operator=(const LinkedList &other) {
        if (this != &other) {  // Check for self-assignment
            // Create a temporary list to copy from 'other'
            LinkedList temp(other);

            // Swap the contents of 'temp' and 'this'
            std::swap(*this, temp);
        }
        return *this;
    }

    // Move assignment operator
    LinkedList &operator=(LinkedList &&other) noexcept {
        if (this != &other) {  // Check for self-assignment
            // Clear the current list
            clear();
            delete guard;

            // Transfer ownership of 'other' to 'this'
            capacity = other.capacity;
            current_size = other.current_size;
            guard = other.guard;

            // Reset 'other'
            other.capacity = 0;
            other.current_size = 0;
            other.guard = nullptr;
        }
        return *this;
    }

    // ################################## Operators ######################################


    // ################################## Basic methods ######################################

    int size() const {
        return current_size;
    }

    bool empty() const {
        return current_size == 0;
    }

    // ################################## Basic methods ######################################


    // ################################## Iterator Methods ######################################

    // returns iterator pointing at the first element
    Iterator begin() const {
        return Iterator{guard->next};
    }

    // returns iterator pointing at the guard
    Iterator end() const {
        return Iterator{guard};
    }

    // adds Node before Node that it is pointing to
    template<class U>
    Iterator insert(Iterator it, U &&x) {

        // creates newNode
        Node *newNode = new Node(std::forward<U>(x));

        // if list is empty creates the first Node
        if (current_size == 0) {

            guard->next = newNode;
            guard->prev = newNode;
            newNode->prev = guard;
            newNode->next = guard;

        } else {

            newNode->prev = it.currentNode->prev;   // newNode->prev now points at the element behind it
            newNode->next = it.currentNode;         // newNode->next now points at it
            it.currentNode->prev = newNode;         // changed current Node->prev to the new node
            newNode->prev->next = newNode;

        }
        ++current_size;
        return Iterator{newNode};
    }

    Iterator erase(Iterator it) {

        Iterator toReturn = Iterator{it.currentNode->next};

        it.currentNode->next->prev = it.currentNode->prev; 
        it.currentNode->prev->next = it.currentNode->next;

        delete it.currentNode;
        current_size--;
        return toReturn;

    }

    // finds the first Node storing data x
    bool find_pair(const Pair<K, V> &x) const {
        Iterator it = begin();

        while (it != end()) {
            if (it.currentNode->data == x) {
                return true;
            }
            ++it;
        }

        return false;
    }

    bool find_key(const K &x) const {
        Iterator it = begin();

        while (it != end()) {
            if (it.currentNode->data.first == x) {
                return true;
            }
            ++it;
        }

        return false;
    }

    // ################################## Iterator Methods ######################################


    // ################################## List Methods ######################################

    // adds Node to the front of the list
    template<class U>
    void push_front(U &&x) {
        if (size() == capacity) {
            throw std::out_of_range("Overflow - capacity reached.");
        }

        insert(begin(), std::forward<U>(x));
    }

    // removes the first element of the list and returns its data
    Pair<K, V> pop_front() {
        if (empty()) {
            throw std::out_of_range("Underflow - list is empty.");
        }

        auto val = guard->next->data;  // stores the first Node's data
        erase(begin());                 // removes the first Node
        return val;                     // returns its data
    }

    // adds a new Node at the end of the list
    template<class U>
    void push_back(U &&x) {
        if (size() == capacity) {
            throw std::out_of_range("Overflow - capacity reached.");
        }

        insert(end(), std::forward<U>(x));
    }

    // removes the last node and returns its data
    Pair<K, V> pop_back() {
        if (empty()) {
            throw std::out_of_range("Underflow - list is empty.");
        }

        auto val = guard->prev->data;             // saves data
        erase(Iterator{guard->prev});       // deletes the last Node
        return val;                            // returns the val of the last Node
    }

    // removes all Nodes(x) and returns the number of Nodes which stored x
    int remove(const Pair<K, V> &x) {
        if (empty()) {
            throw std::out_of_range("Underflow - list is empty.");
        }

        int result = 0;             // counter
        Iterator it = begin();      // iterator = guard->next

        while (it != end()) {
            if (it->data == x) {
                result++;
                erase(it);
                current_size--;
            } else
                ++it;           // if I always increment it erase() is gonna cause skipping of element
        }

        return result;
    }

    // finds Node which stored data == x and erases Node with x then creates newNode in place of it storing y
    template<class U>
    bool replace(const Pair<K, V> &x, U &&y) {
        Iterator firstX = find(x);  // finds the first Node with x

        if (firstX != end())         // checking for success
        {
            insert(erase(firstX), std::forward<U>(y));  // erase old Node(x), insert Node(y) in its place
            return true;
        }

        // element wasn't found
        return false;
    }
    // get method from key
    V& get(const K& key) {
        Iterator it = begin();

        while (it != end()) {
            if (it.currentNode->data.first == key) {
                return it.currentNode->data.second;
            }
            ++it;
        }

        throw std::out_of_range("Underflow - list is empty.");
    }

    // deletes all nodes till guard
    void clear() {

        if (!empty()) {

            Iterator it = begin();

            while (it != end()) {
                it = erase(it);
            }

        }
    }

    // ################################## List Methods ######################################


    // ################################## Destructor ######################################

    ~LinkedList() {
        clear();
        delete guard;
    }

};

#endif //ZESTAW3_LINKEDLIST_HPP

