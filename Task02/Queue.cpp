//
// Created by Jeremi Toroj on 22.10.23.
//

#include <iostream>
#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

const int MAX_CAPACITY = 1e6;

int main()  {
    std::ios_base::sync_with_stdio(false);

    int n_operations;
    std::cin >> n_operations;

    // buffor
    char operation;

    // choose implementation
    LinkedQueue<int,MAX_CAPACITY> queue;
    //ArrayQueue<int,MAX_CAPACITY> queue;

    // handles input
    while(n_operations--) {
        std::cin >> operation;
        if (operation == 'A'){
            int number;
            std::cin >> number;
            queue.push(number);
        }
        else if (operation == 'D'){
            if (!queue.empty()){
                std::cout << queue.pop() << std::endl;
            }
            else
                std::cout << "EMPTY" << std::endl;
        }
        else if (operation == 'S'){
            std::cout << queue.size() << std::endl;
        }
    }



    return 0;
}
