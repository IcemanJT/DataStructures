//
// Created by Jeremi Toroj on 11/10/23.
//

#include <iostream>
#include <string>
#include <random>

int main(int argc, const char *argv[])  {
    std::ios_base::sync_with_stdio(false);

    // checks if we gave program augument
    if (argc != 2){
        std::cout << "wrong number of args" << std::endl;
        return 1;
    }

    // generates random int [0,2] and [0,1e6]
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<int> random_letter(0, 2);
    std::uniform_int_distribution<int> random_number(0, 1e6);

    // array of chars for generator
    std::string letter = "ADS";

    // that many lines program will generate
    int num_of_operations = std::stoi(argv[1]);
    
    for (int i=0;i<num_of_operations;i++){
        char choice = letter[random_letter(gen)];
        if (choice == 'A') {
            std::cout << choice << " " << random_number(gen) << std::endl;
        }
        else {
            std::cout << choice << std::endl;
        }

    }

    return 0;
}