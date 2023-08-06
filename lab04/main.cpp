#include "currency.h"
#include "dollar.h"
#include "BST.h"
#include "BSTNode.h"
#include <iostream>
#include <fstream>

/**
 * Displays the menu of BST ADT operations to the console, so that
 * the user can perform these operations.
 * Pre: bst: BST* pointer to the BST object
 *      is: std::istream& reference to the common input stream
 *      outFS: std::ofstream& reference to the output file stream
 * Post: Modifies the BST, writing data to the fstream pointed to by outFS (log file)
 * Return:
*/
void userMenu(BST* bst, std::istream& is, std::ofstream& outFS) { 
    std::string input;
    std::cout << "Operation: add (a <value>), search (s <value>), delete (d <value>), quit (q)" << std::endl;
    std::getline(is, input);
    while (input != "q") {
        int idx = 0;
        std::string inputs[2];
        std::string temp = "";
        for (int i = 0; i < input.length() && idx < 2; i++) {
            char c = input[i];
            if (c == ' ') {
                inputs[idx++] = temp;
                temp = "";
            } else {
                temp += c;
            }
        }
        
        std::ostringstream msg_stream;
        // Adds the last splitted string to the array
        inputs[idx] = temp;
        Currency* curr = new Dollar("dollar", std::stod(inputs[1]));
        if (inputs[0] == "a") {
            if (bst->search(curr) == NULL) {
                bst->insert(curr);
                msg_stream << "Inserted node with data: " << curr->toString() << std::endl;
            } else {
                msg_stream << "Duplicate data, Insertion Failed" << std::endl;
            }
        } else if (inputs[0] == "s") {
            BSTNode* foundNode = bst->search(curr);
            if (foundNode == NULL) {
                msg_stream << "Node with data " << curr->toString() << " not found" << std::endl;
            } else {
                msg_stream << "Node found with data: " << foundNode->data->toString() << std::endl;
            }
        } else if (inputs[0] == "d") {
            bool removeResult = bst->remove(curr);
            msg_stream << (removeResult ? "Node removed" : "Failed to remove node") << std::endl;
        }

        msg_stream << "BST Level Order Traversal" << std::endl;
        msg_stream << bst->breadthFirstTraversal() << std::endl;
        // Write to both the standard output as well as the log file
        std::string log_msg = msg_stream.str();
        std::cout << log_msg;
        outFS << log_msg;

        input.clear();
        std::cout << "Operation: add (a <value>), search (s <value>), delete (d <value>), quit (q)" << std::endl;

        std::getline(is, input);
    }
}

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #4
 * Has the main runner to demonstrate the working of the Binary Search Tree (BST) ADT 
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

    BST* bst = new BST();
    for (int i = 0; i < 20; i++) {
        bst->insert(currs[i]);
    }

    std::ofstream out;
    out.open("testrun.txt");

    if (!out.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }
    
    std::ostringstream log_oss;
    log_oss << "1) Breadth First Traversal" << std::endl;
    log_oss << bst->breadthFirstTraversal() << std::endl;

    log_oss << "2) Inorder Traversal" << std::endl;
    std::string inorderRes = bst->inorderTraversal();
    log_oss << inorderRes << std::endl;

    log_oss << "3) Preorder Traversal" << std::endl;
    std::string preorderRes = bst->preOrderTraversal();
    log_oss << preorderRes << std::endl;

    log_oss << "4) Postorder Traversal" << std::endl;
    std::string postorderRes = bst->postOrderTraversal();
    log_oss << postorderRes << std::endl;
    
    std::string log_str = log_oss.str();
    std::cout << log_str;
    out << log_str;

    userMenu(bst, std::cin, out);
    log_oss << "1) Breadth First Traversal" << std::endl;
    log_oss << bst->breadthFirstTraversal() << std::endl;

    log_oss << "2) Inorder Traversal" << std::endl;
    inorderRes = bst->inorderTraversal();
    log_oss << inorderRes << std::endl;

    log_oss << "3) Preorder Traversal" << std::endl;
    preorderRes = bst->preOrderTraversal();
    log_oss << preorderRes << std::endl;

    log_oss << "4) Postorder Traversal" << std::endl;
    postorderRes = bst->postOrderTraversal();
    log_oss << postorderRes << std::endl;
    
    log_str = log_oss.str();
    std::cout << "Tree Traversal after changes: " << std::endl << log_str;
    out << "Tree Traversal after changes: " << std::endl << log_str;

    // Close the file output stream after writes
    out.close();
}
