//
// Created by Jeremi Toroj on 12.11.23.
//

#include <iostream>
#include "ArrayList.hpp"

constexpr int CAPACITY = 1000;

int main() {
    std::ios_base::sync_with_stdio(false);

    ArrayList<int, CAPACITY> List;

    int num_of_operations;
    std::cin >> num_of_operations;


    while(num_of_operations--){
        char operation;
        std::cin >> operation;
        if( operation == 'F' ){
            int x;
            std::cin >> x;
            List.push_front(x);
        }
        else if( operation == 'B' ){
            int x;
            std::cin >> x;
            List.push_back(x);
        }
        else if( operation == 'f' ){
            if( List.empty() ){
                std::cout << "EMPTY" << std::endl;
            }
            else {
                std::cout << List.pop_front() << std::endl;
            }
        }
        else if( operation == 'b' ){
            if( List.empty() ){
                std::cout << "EMPTY" << std::endl;
            }
            else {
                std::cout << List.pop_back() << std::endl;
            }
        }
        else if( operation == 'R' ){
            int x;
            int y;
            std::cin >> x;
            std::cin >> y;
            if( List.replace(x, y)){
                std::cout << "TRUE" << std::endl;
            }
            else {
                std::cout << "FALSE" << std::endl;
            }

        }
        else if( operation == 'S' ){
            std::cout << List.size() << std::endl;
        }


    }


}