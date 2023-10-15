#include "BST.h"
#include "queue.h"

class MinHeap: public BST {
    private:
        void percolateDown(BSTNode* heapNode) {
            BSTNode* cur = heapNode;
            double value = cur->data->getAmount();
            while (cur->left != NULL && cur->right != NULL) {
                BSTNode* minNode = NULL;
                double minValue = value;
                double lChildVal = cur->left->data->getAmount();
                double rChildVal = cur->right->data->getAmount();
                if (lChildVal < minValue) {
                    minValue = lChildVal;
                    minNode = cur->left;
                }

                if (rChildVal < minValue) {
                    minValue = rChildVal;
                    minNode = cur->right;
                }

                if (minValue == value) {
                    return;
                } else {
                    // Swaps the smaller child with the current
                    Currency* temp = cur->data;
                    cur->data = minNode->data;
                    minNode->data = temp;
                }
            }
        }

        BSTNode* getParentNode(BSTNode* heapNode) {
            Queue q;
            q.enqueue(root);
            std::string currName = "dollar";

            while (q.countBSTNode() > 0) {
                BSTNode* cur = q.dequeue();
                BSTNode* leftNode = cur->left;
                BSTNode* rightNode = cur->right;

                if (leftNode != NULL && leftNode->data->isEqual(currName, *heapNode->data)) {
                    return cur;
                } else if (leftNode != NULL) {
                    q.enqueue(leftNode);
                }

                if (rightNode != NULL && rightNode->data->isEqual(currName, *heapNode->data)) {
                    return cur;
                } else if (rightNode != NULL) {
                    q.enqueue(rightNode);
                }
            }

            return NULL;
        }

        void percolateUp(BSTNode* heapNode) {      
            std::string curName = "dollar";
     
            while (heapNode != root) {
                BSTNode* parent = getParentNode(heapNode);
                // Parent key must be less than children
                if (parent->data->getAmount() > heapNode->data->getAmount()) {
                    Currency* temp = parent->data;
                    parent->data = heapNode->data;
                    heapNode->data = temp;
                    heapNode = parent;
                } else {
                    return;
                }
            }
        }

    public:
        void insert(Currency* curr) {
            BSTNode* newNode = new BSTNode(curr);
            
            if (root == NULL) {
                root = newNode;
            } else {
                std::string currName = "dollar";
                BSTNode* cur = root;
                if (curr->getAmount() < cur-
            }

            count = count + 1;
        }

        bool remove(Currency* curr) {

        }

        BSTNode* search(Currency* curr) {
            
        }
};