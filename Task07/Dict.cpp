// Creator: Jeremi Toroj
// Date: 26.12.2023

#include "Dict.hpp"
#include <iostream>
#include <fstream>

// add main args
int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }

    Dict<std::string, std::string> dict(70);

    // read file
    std::ifstream file(argv[1]);
    std::string line;
    while (std::getline(file, line))
    {
        std::string key = line.substr(0, line.find(" "));
        std::string value = line.substr(line.find(" ") + 1, line.length());
        std::pair x = std::make_pair(key, value);
        dict.insert(x);
    }

    std::string key;
    while(std::cin >> key){
        if(dict.find(key)){
            std::cout << dict[key] << std::endl;
        }else{
            std::cout << "-" << std::endl;
        }
    }

    return 0;
}
