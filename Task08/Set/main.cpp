#include <iostream>
#include "setList.h"

int main() {
    setList set1, set2;
    
    // Testing insert
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);
    
    // Testing getSize and printSet
    std::cout << "Size of set1: " << set1.getSize() << std::endl;
    std::cout << "Elements in set1: ";
    set1.printSet();
    std::cout << std::endl;
    
    std::cout << "Size of set2: " << set2.getSize() << std::endl;
    std::cout << "Elements in set2: ";
    set2.printSet();
    std::cout << std::endl;
    
    // Testing operator+
    setList set3 = set1 + set2;
    std::cout << "Elements in set3 (union): ";
    set3.printSet();
    std::cout << std::endl;
    
    // Testing operator*
    setList set4 = set1 * set2;
    std::cout << "Elements in set4 (intersection): ";
    set4.printSet();
    std::cout << std::endl;
    
    // Testing operator-
    setList set5 = set1 - set2;
    std::cout << "Elements in set5 (difference): ";
    set5.printSet();
    std::cout << std::endl;
    
    // Testing operator==
    std::cout << "set1 == set1: " << std::boolalpha << (set1 == set1) << std::endl;
    std::cout << "set1 == set3: " << std::boolalpha << (set1 == set3) << std::endl;
    
    // Testing operator<=
    std::cout << "set1 <= set2: " << std::boolalpha << (set1 <= set2) << std::endl;
    std::cout << "set1 <= set3: " << std::boolalpha << (set1 <= set3) << std::endl;
    
    return 0;
}
