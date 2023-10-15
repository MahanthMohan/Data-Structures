#include "currency.h"
#include "dollar.h"
#include "minheap.h"
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

    // Populate the currencies into the min heap
    std::string currName = "dollar";
    MinHeap* minHeap = new MinHeap();
    for (int i = 0; i < 20; i++) {
        minHeap->insert(currs[i]);
    }

    std::string levelOrderRes = minHeap->breadthFirstTraversal();
    std::cout << levelOrderRes << std::endl;
}