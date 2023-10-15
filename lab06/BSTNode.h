#include "currency.h"
#pragma once

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #4
 * This class represents a single node within the BST, with a pointer
 * to the left and the right nodes and one to the parent node.
 * */
class BSTNode {
    public:
        Currency* data;
        BSTNode* left;
        BSTNode* right;

    public:
        BSTNode(Currency* data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        BSTNode(Currency* data, BSTNode* left, BSTNode* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }

        Currency* getData() {
            return data;
        }

        BSTNode* getLeft() {
            return left;
        }

        BSTNode* getRight() {
            return right;
        }
};