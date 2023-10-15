#include "singlylinkedlist.h"
#include "BSTNode.h"
#pragma once

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #4
 * Involves the design of a Queue data structure that adds and
 * removes elements from a SinglyLinkedList in a FIFO manner.
 * Note: Changed this class to reflect the data attribute of
 * the LinkNode, which was changed to a BSTNode* pointer.
 * */
class Queue: public SinglyLinkedList {
    private:
        using SinglyLinkedList::addBSTNode;
        using SinglyLinkedList::appendBSTNode;
        using SinglyLinkedList::getEnd;
        using SinglyLinkedList::getStart;
        using SinglyLinkedList::isListEmpty;
        using SinglyLinkedList::printList;
        using SinglyLinkedList::removeBSTNode;
        using SinglyLinkedList::seqSearch;
        using SinglyLinkedList::prependBSTNode;
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
         * BSTNode object.
         * Pre: data: BSTNode* pointer to the BSTNode object.
         * Post: Initializes an queue with start and end set to the new
         * node containing the given BSTNode object.
         * Return:
        */
        Queue(BSTNode* data): SinglyLinkedList(data) {}
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
         * Pre: curr: BSTNode* pointer to the BSTNode object.
         * Post: Adds the given currency to the end of the queue.
         * Return: bool true or false 
        */
        bool enqueue(BSTNode* curr) {
            bool success = appendBSTNode(curr);
            return success;
        }

        /**
         * Dequeues the currency from the start of the queue.
         * Pre: curr: BSTNode* pointer to the dequeued BSTNode object.
         * Post: Removes the given currency to the start of the queue.
         * Return: BSTNode* pointer to BSTNode or NULL 
        */
        BSTNode* dequeue() {
            LinkNode* head = getStart();
            removeBSTNode(0);
            if (head == NULL) {
                return NULL;
            }

            return head->data;
        }

        /**
         * Returns the currency object at the start of the list
         * Pre:
         * Post:
         * Return: BSTNode* pointer to BSTNode or NULL 
        */
        BSTNode* peekFront() {
            LinkNode* head = getStart();
            if (head == NULL) {
                return NULL;
            }
            
            return head->data;
        }

        /**
         * Returns the currency object at the end of the list
         * Pre:
         * Post:
         * Return: BSTNode* pointer to BSTNode or NULL 
        */
        BSTNode* peekRear() {
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