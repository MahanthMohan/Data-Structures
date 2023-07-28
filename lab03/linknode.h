#include "currency.h"
#pragma once

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #3
 * This assignment involves the design of the data structure SinglyLinkedList,
 * which is a type of linear list that is linked by one pointer between each
 * data container node. Then we proceed to implement LIFO and FIFO queues,
 * in the form of the Stack and Queue data structures that derive properties
 * based on the LinkedList ADT.
 * */
class LinkNode {
    public:
        Currency* data;
        LinkNode* next;

        /**
         * Constructs a new LinkNode with the data and next pointer set to NULL
        */
        LinkNode() {
            this->data = NULL;
            next = NULL;
        }

        /**
         * Constructs a new LinkNode with the data set to a Currency object,
         * and the next pointer set to NULL
        */
        LinkNode(Currency* data) {
            this->data = data;
            next = NULL;
        }
};