//
// Created by Jeremi Toroj on 12.11.23.
//

#ifndef ZESTAW4_ARRAYLIST_HPP
#define ZESTAW4_ARRAYLIST_HPP

#include <stdexcept>

template<class T, int N>
class ArrayList{
private:

    int capacity;
    int current_size;
    T *data;

public:

    /*  explicit forces use of constructor and not assignment operator on type ArrayList
        when ArrayList object is demanded but int is given constructor won't be called

    ArrayList myArrayList = 10;        ---- error

    ArrayList myArrayList(10);          ---- legal

    */
    explicit ArrayList(int cap = N):capacity(cap), current_size(0), data(new T[cap]) {};

    template<class U>
    void push_front(U&& x){
        insert(1, std::forward<U>(x));
    }

    T pop_front(){
        return erase(0);
    }

    template<class U>
    void push_back(U&& x){
        insert(current_size+1, std::forward<U>(x));
    }

    T pop_back(){
        return erase(current_size-1);
    }

    int size(){
        return current_size;
    }

    bool empty(){
        return current_size==0;
    }

    void clear(){
        current_size = 0;
        delete data;
        data = new T[capacity];
    }

    int find(const T& x){

        int result_idx = 0;

        while( result_idx < current_size ){
            if( data[result_idx] == x){
                return result_idx;
            }
            ++result_idx;
        }

        return -1;
    }

    T erase(int i){

        if ( i > size() ){
            throw std::out_of_range("Index out of range.");
        }

        T element = data[i];

        while ( i < size()){
            data[i] = data[i+1];
            ++i;
        }

        --current_size;

        return element;
    }

    template<class U>
    void insert(int i, U&& x){
        if( size() == capacity ){
            throw std::out_of_range("Overflow - capacity reached.");
        }

        int idx = current_size;
        while( idx != i-1 ){
            data[idx] = data[idx-1];
            --idx;
        }

        data[i-1] = std::forward<U>(x);
        ++current_size;
    }

    int remove(const T& x){

        int count = 0;

        for(int idx = 0; idx < size() ; ++idx ){
            if( data[idx] == x ){
                erase(idx);       // erase moves element data[idx-1] to data[idx]
                --idx;              // decrement so remove won't skip element behind idx
                ++count;
            }
        }

        return count;
    }

    template<class U>
    bool replace(const T& x, U&& y){

        int idx = find(x);

        if(  idx != -1 ){
            data[idx] = std::forward<U>(y);
            return true;
        }

        return false;
    }

    ~ArrayList(){
        delete[] data;
    }

};

#endif //ZESTAW4_ARRAYLIST_HPP
