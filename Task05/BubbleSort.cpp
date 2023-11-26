//
// Created by Jeremi Toroj on 26.11.23.
//

#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T>& v) {
    int n = v.size();
    bool swapped;

    do {

        swapped = false;

        for( int i = 1; i < n; ++i ) {
            if( v[i - 1] > v[i] ) {
                std::swap(v[i - 1], v[i]);
                swapped = true;
            }
        }

        // so for doesn't check for sorted part of vector
        --n;

    } while (swapped);

}

int main(){
    std::ios_base::sync_with_stdio(false);

    std::vector<int> v;

    int x;
    while(std::cin >> x){
        v.push_back(x);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sort(v);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;


    return 0;
}