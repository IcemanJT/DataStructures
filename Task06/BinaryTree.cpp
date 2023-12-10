// Creator: Jeremi Toroj
// Date:    10/12/2023

// main
#include <iostream>

#include "BinaryTree.hpp"

int main(){

    BinaryTree<int> tree;

    int elements_to_insert;
    std::cin >> elements_to_insert;

    while(elements_to_insert--){
        int element;
        std::cin >> element;
        tree.insert(element);
    }

    std::cout << tree.current_size() << " " << tree.depth() << " " << tree.minimum() << " " << tree.maximum() << std::endl;

    tree.preorder();

    for( int i = 1; i < 10; ++i ){
        if (tree.search(i)){
            std::cout << "Yes" << std::endl;
        }
        else {
            std::cout << "No" << std::endl;
        }
    }


    
    return 0;
}