#include "linknode.h"
#include "currency.h"
#include "dollar.h"
#include <iostream>
#include <sstream>
#pragma once

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #3
 * This assignment involves the design of the data structure SinglyLinkedList,
 * which is a type of linear list that is linked by one pointer between each
 * data container node.
 * */
class SinglyLinkedList {
    private:
        int count;
        LinkNode* start;
        LinkNode* end;
    
    public:
        /**
         * Constructs a new SinglyLinkedList with start and end
         * set to NULL and count set to 0
         * Pre:
         * Post: start and end set to NULL and count set to 0
         * Return:
        */
        SinglyLinkedList() {
            start = NULL;
            end = NULL;
            count = 0;
        }

        /**
         * Constructs a new SinglyLinkedList with start and
         * end node set to a new node containing Currency object.
         * Pre: data: Currency* the data of the new node
         * Post: start and end node set to a new node containing Currency object
         * Return:
        */
        SinglyLinkedList(Currency* data) {
            LinkNode* newNode = new LinkNode(data);
            start = newNode;
            end = newNode;
            count = 1;
        }

        // Copy Constructor
        /**
         * Copies the data stored within another instance of the
         * SinglyLinkedList to this instance.
         * Pre: other: SinglyLinkedList* pointer to the other linked list
         * Post: Sets the members of this SinglyLinkedList to the data
         * of the other instance pointed to by other
         * Return:
        */
        SinglyLinkedList(SinglyLinkedList* other) {
            LinkNode* otherStart = other->getStart();
            LinkNode* sucNode;

            if (otherStart == NULL) {
                SinglyLinkedList();
                return;
            }

            // Adds all the currs from other to the current list
            while (otherStart != NULL) {
                appendCurrency(otherStart->data);
                otherStart = otherStart->next;
            }
        }

        ~SinglyLinkedList() {
            clearList();
        }

        /**
         * Clears the entire linkedlist, removing all nodes
         * from memory.
         * Pre:
         * Post: Removes all nodes of the SinglyLinkedList,
         * setting the head and tail pointers to null and count to 0
         * Return:
        */
        void clearList() {
            if (start == NULL) {
                return;
            }

            LinkNode* cur = start;
            while (cur != NULL) {
                LinkNode* nextNode = cur->next;
                cur->next = NULL;
                delete cur;
                cur = nextNode;
            }

            start = NULL;
            end = NULL;
            count = 0;
        }

        /**
         * Adds a newly created node with data pointing to the Currency object,
         * at the index given by nodeIndex
         * Pre: cur: a pointer to the Currency object
         * Post: Adds a new node with the given Currency object at nodeIndex
         * Return: bool true or false
        */       
        bool addCurrency(Currency* cur, int nodeIndex) {
            LinkNode* newNode = new LinkNode(cur);

            if (nodeIndex == -1) {
                return false;
            } else if (start == NULL) {
                start = newNode;
                end = newNode;
            } else if (nodeIndex == 0) {
                newNode->next = start;
                start = newNode;
            } else if (nodeIndex >= count) {
                return false;
            } else {
                int counter = 0;
                LinkNode* prev = start;
                while (counter < nodeIndex - 1 && prev->next != NULL) {
                    prev = prev->next;
                    counter = counter + 1;
                }

                LinkNode* cur = prev->next;
                if (cur == NULL) {
                    end->next = newNode;
                    end = newNode;
                    count = count + 1;
                    return true;
                }

                newNode->next = cur;
                prev->next = cur;
            }

            count = count + 1;
            return true;
        }

        /**
         * Appends the given Currency object to the end of the SinglyLinkedList.
         * Pre: cur: a pointer to the Currency object
         * Post: Adds a new node with the given Currency object after end,
         * reassigning end to the new node 
         * Return: bool true or false
        */   
        bool appendCurrency(Currency* cur) {
            LinkNode* newNode = new LinkNode(cur);
            
            if (start == NULL) {
                start = newNode;
                end = newNode;
            } else {
                end->next = newNode;
                end = newNode;
            }

            count = count + 1;
            return true;
        }

        /**
         * Prepends the given Currency object to the start of the SinglyLinkedList.
         * Pre: cur: a pointer to the Currency object
         * Post: Adds a new node with the given Currency object before start,
         * reassigning start to the new node 
         * Return: bool true or false
        */        
        bool prependCurrency(Currency* cur) {
            LinkNode* newNode = new LinkNode(cur);
            
            if (start == NULL) {
                start = newNode;
                end = newNode;
            } else {
                newNode->next = start;
                start = newNode;
            }

            count = count + 1;
            return true;
        }

        /**
         * Searches for the node with data containing the given Currency curr
         * Pre: curr: a pointer to the Currency object
         * Post:
         * Return: int between 0 and count - 1 inclusive.
        */
        int seqSearch(Currency* curr) {
            LinkNode* cur = start;
            int foundIdx = 0;
            while (cur != NULL) {
                std::string currType = "dollar";
                if (cur->data->isEqual(currType, *curr)) {
                    return foundIdx;
                }

                cur = cur->next;
                foundIdx = foundIdx + 1;
            }

            return -1;
        }

        /**
         * Removes the node at the given nodeIndex that has the given Currency object.
         * Pre: curr: a pointer to the Currency object
         * Post: Removes the node contains given Currency, changing it and returning
         * the removed Currency object for the deleted node.
         * Return: Currency* pointer to Currency object or NULL
        */
        Currency* removeCurrency(Currency* curr) {
            std::string curName = "dollar";
            if (start == NULL) {
                return NULL;
            } else if (start == end) {
                delete start;
                start = end = NULL;
            } else if (start->data->isEqual(curName, *curr)) {
                LinkNode* nextNode = start->next;
                delete start;
                start = nextNode;
            }

            LinkNode* predNode = start;
            while (predNode->next != NULL && !predNode->next->data->isEqual(curName, *curr)) {
                predNode = predNode->next;
            }

            LinkNode* curNode = predNode->next;
            if (curNode == NULL) {
                return NULL;
            } else if (curNode == end) {
                end = predNode;
                predNode->next = NULL;
                delete curNode;
            } else {
                LinkNode* sucNode = curNode->next;
                predNode->next = sucNode;
                delete curNode;
            }

            count = count - 1;
            return curr;
        }

        /**
         * Removes the node at the given nodeIndex in the range [0, count - 1],
         * returning the removed Currency object.
         * Pre: nodeIndex: an integer value for the index of the node.
         * Post: Removes a node from the list, changing it and returning the removed Currency object
         * for the deleted node.
         * Return: Currency* pointer to Currency object or NULL
        */
        Currency* removeCurrency(int nodeIndex) {
            if (start == NULL) {
                return NULL;
            } else if (nodeIndex >= count) {
                return NULL;
            } else if (nodeIndex == 0) {
                LinkNode* nextNode = start->next;
                Currency* removed = start->data;
                delete start;
                start = nextNode;
                count = count - 1;
                return removed;
            }

            LinkNode* prev = start;
            int counter = 0;

            // Follow the list pointer up until the node before the node at nodeIndex
            while (counter < nodeIndex - 1 && prev->next != NULL) {
                prev = prev->next;
                counter = counter + 1;
            }

            LinkNode* cur = prev->next;
            // If the node is not found
            if (cur == NULL) {
                return NULL;
            }

            Currency* removed = cur->data;
            prev->next = cur->next;
            delete cur;

            count = count - 1;
            return removed;
        }

        /**
         * Returns a boolean of true or false depending on whether the
         * number of elements in the list is 0 or not.
         * Pre:
         * Post:
         * Return: bool true or false 
        */
        bool isListEmpty() {
            return count == 0;
        }

        /**
         * Returns a pointer to the start node of the list.
         * Pre:
         * Post:
         * Return: LinkNode* pointer that points to start or NULL
        */
        LinkNode* getStart() {
            return start;
        }


        /**
         * Returns a pointer to the end node of the list.
         * Pre:
         * Post:
         * Return: LinkNode* pointer that points to end or NULL
        */
        LinkNode* getEnd() {
            return end;
        }

        
        /**
         * Returns a string representation of the list, spaced by tab.
         * Pre:
         * Post:
         * Return: std::string "" or some string of characters.
        */
        std::string printList() {
            std::ostringstream oss;
            LinkNode* cur = start;
            for (cur = start; cur != NULL; cur = cur->next) {
                oss << cur->data->toString() << "\t";
            }

            return oss.str();
        }

        /**
         * Returns the count of total number of nodes in the list,
         * i.e currency count
         * Pre:
         * Post:
         * Return: int the count of total number of nodes in the list
        */
        int countCurrency() {
            return count;
        }
};