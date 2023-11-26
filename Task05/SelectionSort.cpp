//
// Created by Jeremi Toroj on 26.11.23.
//

#include <vector>

template <class T>
void sort(std::vector<T>& v) {
    int n = v.size();

    for( int i = 0; i < n - 1; ++i ) {
        int minIndex = i;

        for( int j = i + 1; j < n; ++j ) {

            if (v[j] < v[minIndex]) {
                minIndex = j;
            }

        }

        // swapping lowest found element with current idx
        if (minIndex != i) {
            std::swap(v[i], v[minIndex]);
        }
    }
}

int main(){

    return 0;
}