//
// Created by Jeremi Torój on 26.11.23.
//

#include <iostream>
#include <random>

int main(int argc, const char *argv[]) {

    std::ios_base::sync_with_stdio(false);

    if( argc != 3 ){
        throw std::runtime_error("Too few arguments.");
    }

    int num_of_data = std::stoi(argv[1]);
    int max_int = std::stoi(argv[2]);

    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<int> rand_number(1, max_int);


    while(num_of_data--){
        std::cout << rand_number(gen) << std::endl;
    }


    return 0;
}