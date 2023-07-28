#include "singlylinkedlist.h"
#pragma once

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #3
 * Involves the design of a Stack data structure that adds and
 * removes elements from a SinglyLinkedList in a LIFO manner.
 * */
class Stack: public SinglyLinkedList {
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
         * Constructs an empty stack.
         * Pre:
         * Post: Initializes an empty stack with start and end set to NULL
         * Return:
        */
        Stack(): SinglyLinkedList() {}

        /**
         * Constructs a stack with the the head and tail set to the given
         * Currency object.
         * Pre: data: Currency* pointer to the Currency object.
         * Post: Initializes an stack with start and end set to the new
         * node containing the given Currency object.
         * Return:
        */
        Stack(Currency* data): SinglyLinkedList(data) {}
        /**
         * Constructs a stack, copying the contents of the stack pointed
         * to by other.
         * Pre: other: Stack* pointer to the other Stack instance.
         * Return:
        */
        Stack(Stack* other): SinglyLinkedList(other) {}

        /**
         * Pushes the currency, with the new LinkNode added to the start
         * of the stack. Sets the start of the stack to the new node.
         * Pre: curr: Currency* pointer to the Currency object.
         * Post: Adds the given currency to the start of the stack.
         * Return: bool true or false 
        */
        bool push(Currency* curr) {
            bool success = addCurrency(curr, 0);
            return success;
        }

        /**
         * Pops the currency from the start of the stack.
         * Pre: curr: Currency* pointer to the popped Currency object.
         * Post: Removes the given currency from the start of the queue.
         * Return: Currency* pointer to Currency or NULL 
        */
        Currency* pop() {
            Currency* removed = removeCurrency(0);
            return removed;
        }

        /**
         * Returns the currency object at the start of the stack
         * Pre:
         * Post:
         * Return: Currency* pointer to Currency or NULL 
        */
        Currency* peek() {
            LinkNode* head = getStart();
            if (head != NULL) {
                return head->data;
            }
            
            return NULL;
        }

        /**
         * Returns a string representation of the stack, spaced by tab.
         * Pre:
         * Post:
         * Return: std::string "" or some string of characters.
        */
        std::string printStack() {
            return printList();
        }
};