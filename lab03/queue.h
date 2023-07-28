#include "singlylinkedlist.h"
#pragma once

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #3
 * Involves the design of a Queue data structure that adds and
 * removes elements from a SinglyLinkedList in a FIFO manner.
 * */
class Queue: public SinglyLinkedList {
    private:
        using SinglyLinkedList::addCurrency;
        using SinglyLinkedList::appendCurrency;
        using SinglyLinkedList::getEnd;
        using SinglyLinkedList::getStart;
        using SinglyLinkedList::isListEmpty;
        using SinglyLinkedList::printList;
        using SinglyLinkedList::removeCurrency;
        using SinglyLinkedList::seqSearch;
        using SinglyLinkedList::prependCurrency;
        using SinglyLinkedList::clearList;

    public:
        /**
         * Constructs an empty queue.
         * Pre:
         * Post: Initializes an empty queue with start and end set to NULL
         * Return:
        */
        Queue(): SinglyLinkedList() {}

        /**
         * Constructs a queue with the the head and tail set to the given
         * Currency object.
         * Pre: data: Currency* pointer to the Currency object.
         * Post: Initializes an queue with start and end set to the new
         * node containing the given Currency object.
         * Return:
        */
        Queue(Currency* data): SinglyLinkedList(data) {}
        /**
         * Constructs a queue, copying the contents of the queue pointed
         * to by other.
         * Pre: other: Queue* pointer to the other Queue instance.
         * Return:
        */
        Queue(Queue* other): SinglyLinkedList(other) {}

        /**
         * Enqueues the currency, with the new LinkNode added to the end
         * of the queue. Sets the end of the queue to the new node.
         * Pre: curr: Currency* pointer to the Currency object.
         * Post: Adds the given currency to the end of the queue.
         * Return: bool true or false 
        */
        bool enqueue(Currency* curr) {
            bool success = appendCurrency(curr);
            return success;
        }

        /**
         * Dequeues the currency from the start of the queue.
         * Pre: curr: Currency* pointer to the dequeued Currency object.
         * Post: Removes the given currency to the start of the queue.
         * Return: Currency* pointer to Currency or NULL 
        */
        Currency* dequeue() {
            LinkNode* head = getStart();
            Currency* popped = removeCurrency(0);
            return popped;
        }

        /**
         * Returns the currency object at the start of the list
         * Pre:
         * Post:
         * Return: Currency* pointer to Currency or NULL 
        */
        Currency* peekFront() {
            LinkNode* head = getStart();
            if (head != NULL) {
                return head->data;
            }
            
            return NULL;
        }

        /**
         * Returns the currency object at the end of the list
         * Pre:
         * Post:
         * Return: Currency* pointer to Currency or NULL 
        */
        Currency* peekRear() {
            LinkNode* tail = getEnd();
            if (tail != NULL) {
                return tail->data;
            }

            return NULL;
        }

        /**
         * Returns a string representation of the queue, spaced by tab.
         * Pre:
         * Post:
         * Return: std::string "" or some string of characters.
        */
        std::string printQueue() {
            return printList();
        }
};