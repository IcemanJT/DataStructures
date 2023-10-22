//
// Created by Jeremi Toroj on 18/10/23.
//

#include <iostream>
#include "ArrayStack.hpp"
#include "LinkedStack.hpp"

// const - function won't change str, & - cpp won't make copy
bool isNumber(const std::string& str){
    if (std::isdigit(str[0])){
        return true;
    }
    return false;
}

// checks if first sign of str is +, -, * or /
bool isOpperand(const std::string& str){
    if(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
        return true;
    return false;
}

// checks if input is )
bool isClosingBraket(const std::string& str){
    if (str[0]==')'){
        return true;
    }
    return false;
}

int main(){

    ArrayStack<char> stack(100);
    //LinkedStack<char> stack(100);

    std::string input;

    // string holding result
    std::string result;

    // handles input
    while(std::cin >> input){
        if (isNumber(input)){
            result += input;
            result += " ";
        }
        else if(isOpperand(input)){

            stack.push(input[0]);
        }
        else if(isClosingBraket(input)){
            result += stack.pop();
            result += " ";
        }
    }

    // trims string of everything except between first not withe sign and last not white sign
    result = result.substr(result.find_first_not_of(" \t\n"), result.find_last_not_of(" \t\n") + 1);

    std::cout << result << std::endl;

    return 0;
}
