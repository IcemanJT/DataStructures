//
// Created by Jeremi Toroj on 11/10/23.
//

#include <iostream>
#include "LinkedStack.hpp"
#include "ArrayStack.hpp"

int main(int args, char** argv)  {
    std::ios_base::sync_with_stdio(false);

    // reads first number which is stack capacity
    int capacity;
    std::cin >> capacity;

    // buffor
    std::string input;

    // choose implementation
    //LinkedStack<int> stack(capacity);
    ArrayStack<int> stack(capacity);

    // handles input
    while(std::cin >> input) {
        char operation = input[0];
        if (operation == 'A'){
            std::cin >> input;
            stack.push(std::stoi(input));
        }
        else if (operation == 'D'){
            if (!stack.empty()){
                std::cout << stack.pop() << std::endl;
            }
            else
                std::cout << "EMPTY" << std::endl;
        }
        else if (operation == 'S'){
            std::cout << stack.size() << std::endl;
        }
    }



    return 0;
}
