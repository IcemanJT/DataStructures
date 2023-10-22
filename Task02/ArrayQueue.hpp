//
// Created by Jeremi Toroj on 22.10.23.
//

#ifndef ZESTAW2_ARRAYQUEUE_HPP
#define ZESTAW2_ARRAYQUEUE_HPP

#include <stdexcept>

template <typename T, int N>
class ArrayQueue{
private:

    T *data;
    int head;
    int tail;
    int current_size;
    int capacity;

public:

    // constructor
    ArrayQueue(){
        head = 0;
        tail = 0;
        current_size = 0;
        capacity = N;
        data = new T[N];
    }

    bool empty(){
        return current_size==0;
    }

    int size(){
        return current_size;
    }

    T& front(){
      if(empty()){
          throw std::out_of_range("Underflow - queue is empty.");
      }

      return data[head];
    }

    T pop(){
        if(empty()){
            throw std::out_of_range("Underflow - queue is empty.");
        }

        current_size--;
        T popped_val = data[head];
        data[head] = T();
        head = (head + 1) % capacity;
        return popped_val;
    }

    template<class U>
    void push(U&& arg){ // universal/forwarding reference
        if(size() == capacity){
            throw std::out_of_range("Overflow - queue is full.");
        }

        current_size++;
        data[tail] = std::forward<U>(arg); // perfect forwarding
        tail = (tail + 1) % capacity;
    }

    ~ArrayQueue(){
        delete data;
    }

};

#endif //ZESTAW2_ARRAYQUEUE_HPP
