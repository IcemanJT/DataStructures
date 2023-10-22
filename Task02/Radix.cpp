//
// Created by Jeremi Toroj on 22.10.23.
//

#include <iostream>
#include <vector>
// #include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

const int MAX_CAP = 1e6;

void radix(std::vector<int>& v){
    int d_position = 10; // cutting number to position of d-th
    int k_postion = 1; // for substracting numbers before d-th positoin

    ArrayQueue<int,MAX_CAP> queues[10];

    for(int i =0;i<10;i++){

        for(const auto& num: v){
            int digit_index = ((num % d_position) - (num % k_postion))/k_postion;
            queues[digit_index].push(num);
        }

        v.clear();

        for(auto& queue : queues){
            while(!(queue.empty()))
                v.push_back(queue.pop());
        }

        d_position *= 10;
        k_postion *= 10;
    }

}


int main(){
    std::ios_base::sync_with_stdio(false);

    std::string x;
    std::vector<int> container;

    while(std::cin >> x) {
        container.push_back(std::stoi(x));
    }

    radix(container);

    std::cout << "-----results----" << std::endl;
    for(const auto& element: container){
        std::cout << element << std::endl;
    }

    return 0;
}