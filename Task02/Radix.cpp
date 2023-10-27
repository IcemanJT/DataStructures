//
// Created by Jeremi Toroj on 22.10.23.
//

#include <iostream>
#include <vector>

// #include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

const int MAX_CAP = 1000000;

void radix(std::vector<int>& v){
    int d_position = 10; // cutting number to position of d-th
    int k_postion = 1; // for substracting numbers before d-th positoin

    // array of 10 queues
    ArrayQueue<int,MAX_CAP> queues[10];

    // sorting
    // ++i should be more efficient, post incrementation creats a copy
    for (int i =0;i<10;++i){

        // placing elements in queues

        // calculates index of queue for exmaple 1234 % 100 = 34
        // now we need to subtract everything past 3 and make it a single digit so
        // 34 - (34 % 10) = 30 - > 30 / 10 = 3 and so on until 10^9
        for (const auto& num: v){
            int digit_index = ((num % d_position) - (num % k_postion))/k_postion;
            queues[digit_index].push(num);
        }

        // clears vector
        v.clear();

        // puttin elements backt to vector
        for (auto& queue : queues){
            while (!(queue.empty()))
                v.push_back(queue.pop());
        }

        // incrementig mods == next digit to sort at
        d_position *= 10;
        k_postion *= 10;
    }

}


int main(){
    std::ios_base::sync_with_stdio(false);

    std::string x;
    std::vector<int> container;

    while (std::cin >> x) {
        container.push_back(std::stoi(x));
    }

    radix(container);

    for (const auto& element: container){
        std::cout << element << std::endl;
    }

    return 0;
}
