//
// Created by Jeremi Toroj on 26.11.23.
//

#include <iostream>
#include <vector>


template <class T>
void sort(std::vector<T>& v) {
    int n = v.size();

    for( int i = 1; i < n; ++i ) {
        T key = v[i];
        int j = i - 1;

        while( j >= 0 && v[j] > key ) {
            v[j + 1] = v[j];
            j -= 1;
        }

        v[j + 1] = key;
    }
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
