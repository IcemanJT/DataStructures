//
// Created by Jeremi Torój on 22.10.23.
//

#ifndef ZESTAW2_ARRAYQUEUE_HPP
#define ZESTAW2_ARRAYQUEUE_HPP

#include <stdexcept>

template <typename T, int N>
class ArrayQueue{
private:

    T *data;            // T type data array
    int head;           // index of first element in the queue
    int tail;           // index of space behind last element
    int current_size;   // current queue size - number of elements
    int capacity;       // that many elements queue can hold

public:

    // constructor
    ArrayQueue(){
        head = 0;
        tail = 0;
        current_size = 0;
        capacity = N;
        data = new T[N];
    }

    // checks if queue is empty
    bool empty(){
        return current_size==0;
    }

    // returns current size
    int size(){
        return current_size;
    }

    // returns referenace to type T - first element in the queue
    T& front(){
      if(empty()){
          throw std::out_of_range("Underflow - queue is empty.");
      }

      return data[head];
    }

    // pops value of the first element and returns it
    T pop() {
        if (empty()) {
            throw std::out_of_range("Underflow - queue is empty.");
        }

        current_size--;
        T popped_val = data[head];
        data[head] = T();               // sets value stored at first place to typname initilization value
        head = (head + 1) % capacity;   // zeroes head index if it goes out of range
        return popped_val;
    }

    template<class U>
    void push(U&& arg){             // universal/forwarding reference
        if (size() == capacity){
            throw std::out_of_range("Overflow - queue is full.");
        }

        current_size++;
        data[tail] = std::forward<U>(arg); // perfect forwarding
        tail = (tail + 1) % capacity;
    }
    /*
     *  Universal referance and perfect forwading
     *
     *  U&& preservs the type on arg which means if we pass:
     *
     *  const int x;
     *  it will be referance to const int lvalue
     *
     *  then std::forward(arg) for example:
     *  string s = "abc";
     *  string new_s = std::forward(s) // now s = "", new_s = "abc" without making a copy
     *
     *  using perfect forwading lvalue stays lvalue and same for rvalues
     *  which is desired for implementations such as queues and using tamplates
     *
     *  std::move changes lvalues to rvalues which we don't want to
     *  beacuse change might be unintensional
     *
    */

    // destructor frees memory
    ~ArrayQueue(){
        delete data;
    }

};

#endif //ZESTAW2_ARRAYQUEUE_HPP
