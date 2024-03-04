#include "setBST.h"
#include <iostream>

int main() {
    setBST set;

    // Insert some elements
    set.insert(5);
    set.insert(3);
    set.insert(7);
    set.insert(1);
    set.insert(4);
    set.insert(6);
    set.insert(8);

    std::cout << "Set size: " << set.getSize() << std::endl;

    // Print the set
    std::cout << "Set contents: ";
    set.printSet();
    std::cout << std::endl;

    // Test isInSet
    std::cout << "Is 5 in the set? " << (set.isInSet(5) ? "Yes" : "No") << std::endl;
    std::cout << "Is 10 in the set? " << (set.isInSet(10) ? "Yes" : "No") << std::endl;

    // Test withdraw
    set.withdraw(3);
    std::cout << "After withdrawing 3: ";
    set.printSet();
    std::cout << std::endl;

    // Test intersection
    setBST set2;
    set2.insert(3);
    set2.insert(7);
    set2.insert(9);

    setBST intersectionSet = set * set2;
    std::cout << "Intersection set contents: ";
    intersectionSet.printSet();
    std::cout << std::endl;

    // Test subtraction
    setBST subtractSet = set - set2;
    std::cout << "Subtraction set contents: ";
    subtractSet.printSet();
    std::cout << std::endl;

    // Test subset
    setBST subsetSet;
    subsetSet.insert(5);
    subsetSet.insert(7);

    std::cout << "Is {";
    set2.printSet();
    std::cout << "} a subset of {";
    set.printSet();
    std::cout << "} ? " << (set2 <= set ? "Yes" : "No") << std::endl;

    // Test equality
    setBST equalSet = set;
    std::cout << "Are {";
    equalSet.printSet();
    std::cout << "} and {";
    set.printSet();
    std::cout << "} equal? " << (equalSet == set ? "Yes" : "No") << std::endl;


    subtractSet.withdraw(1);
    // print each set in a row
    std::cout << "Set contents: ";
    set.printSet();
    std::cout << std::endl;
    std::cout << "Set2 contents: ";
    set2.printSet();
    std::cout << std::endl;
    std::cout << "Intersection set contents: ";
    intersectionSet.printSet();
    std::cout << std::endl;
    std::cout << "Subtraction set contents: ";
    subtractSet.printSet();
    std::cout << std::endl;
    std::cout << "Subset set contents: ";
    subsetSet.printSet();
    std::cout << std::endl;
    std::cout << "Equal set contents: ";
    equalSet.printSet();
    std::cout << std::endl;


    return 0;
}
