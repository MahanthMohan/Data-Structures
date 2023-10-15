#include "currency.h"
#include "dollar.h"
#include "hashtable.h"
#include <iostream>

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #5
 * Has the main runner to demonstrate the working of the HashTable ADT
 * */
int main() {
    // Constructs an array with 20 dollar objects
    Currency* currs[] = {new Dollar("dollar", 57.12), new Dollar("dollar", 23.44), new Dollar("dollar", 87.43),
                         new Dollar("dollar", 68.99), new Dollar("dollar", 111.22), new Dollar("dollar", 44.55),
                         new Dollar("dollar", 77.77), new Dollar("dollar", 18.36), new Dollar("dollar", 543.21),
                         new Dollar("dollar", 20.21), new Dollar("dollar", 345.67), new Dollar("dollar", 36.18),
                         new Dollar("dollar", 48.48), new Dollar("dollar", 101.00), new Dollar("dollar", 11.00),
                         new Dollar("dollar", 21), new Dollar("dollar", 51), new Dollar("dollar", 1),
                         new Dollar("dollar", 251), new Dollar("dollar", 151)};

    // Populate the currencies into the hash table
    std::string currName = "dollar";
    HashTable* hTable = new HashTable(29);
    for (int i = 0; i < 20; i++) {
        hTable->insert(currs[i]);
    }

    std::cout << hTable->toString();
    std::string input;
    std::cout << "Enter dollar amount to search for (q for quit)" << std::endl;
    std::cout << "Value: ";
    std::getline(std::cin, input);
    while (input != "q") {
        double d = std::stod(input);
        int bucketIdx = hTable->search(new Dollar(currName, d));
        if (bucketIdx != -1) {
            std::cout << "Value " << d << " found at bucket index " << bucketIdx << std::endl;
        } else {
            std::cout << "Invalid Data" << std::endl;
        }
        std::cout << "Enter dollar amount to search for (q for quit)" << std::endl;
        std::cout << "Value: ";
        std::getline(std::cin, input);
    }
}