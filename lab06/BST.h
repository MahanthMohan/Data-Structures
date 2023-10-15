#include "BSTNode.h"
#include "queue.h"
#include <iostream>
#pragma once

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #4
 * This class represents a Binary Search Tree (BST) ADT, with a root node and a
 * count of the elements in the tree. It defines common operations on
 * a tree, such as insert, remove, search, traversal, count among others.
 * */
class BST {
    protected:
        BSTNode* root;
        int count;

        /**
         * Helper method for inorder traversal of the BST.
        */
        void printInorder(std::ostringstream& oss, BSTNode* node) {
            if (node == NULL) {
                return;
            }

            printInorder(oss, node->left);
            oss << node->data->toString() << " ";
            printInorder(oss, node->right);            
        }

        /**
         * Helper method for preorder traversal of the BST.
        */
        void printPreOrder(std::ostringstream& oss, BSTNode* node) {
            if (node == NULL) {
                return;
            }

            oss << node->data->toString() << " ";
            printPreOrder(oss, node->left);
            printPreOrder(oss, node->right);            
        }
    
        /**
         * Helper method for postorder traversal of the BST.
        */
        void printPostOrder(std::ostringstream& oss, BSTNode* node) {
            if (node == NULL) {
                return;
            }

            printPostOrder(oss, node->left);
            printPostOrder(oss, node->right);            
            oss << node->data->toString() << " ";
        }

        /**
         * Recursively calculates the height of the BST
        */
        int height(BSTNode* node) {
            if (node == NULL) {
                return -1;
            }

            return 1 + max(height(node->left), height(node->right));
        }

        /**
         * Helper for finding the maximum of two heights (integers)
        */
        int max(int a, int b) {
            return (a > b) ? a : b;
        }

    protected:
        /**
         * Constructs a new BST with the root set to NULL and count to 0.
         * Pre:
         * Post: BST's root set to NULL and node count to 0.
         * Return:
        */
        BST() {
            root = NULL;
            count = 0;
        }

        /**
         * Constructs a new BST with the root set to the node parameter and count to 1.
         * Pre: node: BSTNode* pointer to the data.
         * Post: BST's root set to the node pointer and count to 1.
         * Return:
        */
        BST(BSTNode* node) {
            root = node;
            count = 1;
        }

        /**
         * Constructs a new BST with the root set to BSTNode with data given by the cur
         * Currency pointer.
         * Pre: cur: Currency* pointer to the data.
         * Post: BST's root set to the constructed node object and count to 1.
         * Return:
        */
        BST(Currency* cur) {
            BSTNode* newNode = new BSTNode(cur);
            root = newNode;
            count = 1;
        }

        /**
         * Destructs the BST, removing all nodes by traversing through them,
         * and deleting the node pointers.
         * Pre:
         * Post: Removes all nodes in the BST, setting node count to 0
         * Return:
        */
        ~BST() {
            empty(root);
            count = 0;
            root = NULL;
        }

        /**
         * Searches a given node within the BST, returning the pointer
         * to the node where the currency was found or NULL if not found.
         * Pre: target: Currency* pointer to the currency to be searched
         * Post:
         * Return: BSTNode* pointer to tree node or NULL
        */
        virtual BSTNode* search(Currency* target) {
            BSTNode* cur = root;
            std::string currName = "dollar";

            while (cur != NULL) {
                if (cur->data->isEqual(currName, *target)) {
                    return cur; 
                } else if (cur->data->isGreater(currName, *target)) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }

            return NULL;
        }


        /**
         * Inserts a given currency into the BST, updating the pointers as
         * necessary to reflect changes. Does not rebalance the tree.
         * Pre: target: Currency* pointer to the currency to be inserted
         * Post: BST is changed, with the new node inserted. Child and parent
         * pointers are updated as a result.
         * Return:
        */
        virtual void insert(Currency* newCurr) {
            BSTNode* newNode = new BSTNode(newCurr);
            
            if (root == NULL) {
                root = newNode;
            } else {
                BSTNode* cur = root;
                std::string currName = "dollar";

                while (cur != NULL) {
                    if (cur->data->isGreater(currName, *newCurr)) {
                        if (cur->left == NULL) {
                            cur->left = newNode;
                            cur = NULL;
                        } else {
                            cur = cur->left;
                        }
                    } else {
                        if (cur->right == NULL) {
                            cur->right = newNode;
                            cur = NULL;
                        } else {
                            cur = cur->right;
                        }
                    }
                }
            }

            count = count + 1;
        }

        /**
         * Removes a given currency from the BST, returning a result of 
         * true of false depending on whether removal is successful.
         * Pre: curr: Currency* pointer to the currency to be removed.
         * Post: Removes node containing the given currency, updating
         * the pointers accordingly.
         * Return: bool true or false
        */
        virtual bool remove(Currency* curr) {
            BSTNode* par = NULL;
            BSTNode* cur = root;
            std::string currName = "dollar";

            while (cur != NULL) {
                if (cur->data->isEqual(currName, *curr)) {
                    if (cur->left == NULL && cur->right == NULL) {
                        if (par == NULL) {
                            delete root;
                            root = NULL;
                        } else if (par->left == cur) {
                            par->left = NULL;
                            delete cur;
                        } else {
                            delete par->right;
                            par->right = NULL;
                        }
                    } else if (cur->right == NULL) {
                        if (par == NULL) {
                            delete root;
                            root = cur->left;
                        } else if (par->left == cur) {
                            par->left = cur->left;
                            delete cur;
                        } else {
                            par->right = cur->left;
                            delete cur;
                        }
                    } else if (cur->left == NULL) {
                        if (par == NULL) {
                            delete root;
                            root = cur->right;
                        } else if (par->left == cur) {
                            par->left = cur->right;
                            delete cur;
                        } else {
                            par->right = cur->right;
                            delete cur;
                        }
                    } else {
                        // Recursively remove node and replaced it with the successor
                        BSTNode* suc = cur->right;
                        while (suc->left != NULL) {
                            suc = suc->left;
                        }

                        Currency* sucData = suc->data;
                        remove(sucData);
                        cur->data = sucData;
                    }

                    count = count - 1;
                    return true;
                } else if (cur->data->isGreater(currName, *curr)) {
                    par = cur;
                    cur = cur->left;
                } else {
                    par = cur;
                    cur = cur->right;
                }
            }

            return false;
        }

        /**
         * Gets the count of the total number of nodes in the BST.
         * Pre:
         * Post:
         * Return: int (n >= 0)
        */
        int getCount() {
            return count;
        }

        /**
         * Returns a boolean, representing whether the tree is empty or not.
         * Pre:
         * Post:
         * Return: bool true or false
        */
        bool isEmpty() {
            return root == NULL;
        }

        /**
         * Calculates the height of the BST, by recursively finding height of each
         * subtree and finding maximum of the heights.
         * Pre:
         * Post:
         * Return: int (n >= 0)
        */
        int getHeight() {
            return height(root); 
        }

        /**
         * Destructs the BST, removing all nodes within the tree from bottom up,
         * setting count to 0 and the root ptr to NULL
         * Pre: node: BSTNode* ptr to the current node
         * Post: Removes all nodes in the BST, setting node count to 0, 
         * root ptr to NULL
         * Return:
        */
        void empty(BSTNode* node) {
            if (node == NULL) {
                return;
            }

            empty(node->left);
            empty(node->right);
            delete node;
        }

    public:
        /**
         * Prints out the data of each node in the BST while traversing it
         * left to right, hence breadth first traversal
         * Pre:
         * Post:
         * Return: std::string "" or some string of chars
        */
        std::string breadthFirstTraversal() {
            if (root == NULL) {
                return "";
            }

            std::ostringstream oss;
            Queue q;
            q.enqueue(root);
            while (q.countBSTNode() > 0) {
                BSTNode* first = q.peekFront();
                oss << first->data->toString() << " ";
                q.dequeue();

                if (first->left != NULL) {
                    q.enqueue(first->left);
                }
                
                if (first->right != NULL) {
                    q.enqueue(first->right);
                }
            } 

            return oss.str();
        }

        /**
         * Prints out the data of each node in the BST while traversing it
         * in order, in a left-center-right scheme.
         * Pre:
         * Post:
         * Return: std::string "" or some string of chars
        */
        std::string inorderTraversal() {
            std::ostringstream oss;
            printInorder(oss, root);
            return oss.str();
        }

        /**
         * Prints out the data of each node in the BST while traversing it
         * in order, in a center-left-right scheme.
         * Pre:
         * Post:
         * Return: std::string "" or some string of chars
        */
        std::string preOrderTraversal() {
            std::ostringstream oss;
            printPreOrder(oss, root);
            return oss.str();
        }

        /**
         * Prints out the data of each node in the BST while traversing it
         * in order, in a left-right-center scheme to a string.
         * Pre:
         * Post:
         * Return: std::string "" or some string of chars
        */
        std::string postOrderTraversal() {
            std::ostringstream oss;
            printPostOrder(oss, root);
            return oss.str();
        }
};
