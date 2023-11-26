//
// Created by Jeremi Toroj on 26.11.23.
//

#include <iostream>
#include <vector>

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

    sort(v);

    for(const auto& element: v){
        std::cout << element << std::endl;
    }


    return 0;
}
