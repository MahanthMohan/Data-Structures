#include <iostream>
#include <string>
#include "currency.h"
#include "dollar.h"
#include "pound.h"

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #2
 * This assignment involves the design of classes Currency, Dollar, and Pound to
 * demonstrate the principles of object oriented programming such as inheritance,
 * polymorphism (different behaviors), abstraction (hiding details of implementation),
 * and encapsulation (hiding information).
 * */
int main() {
    Currency* currs[2];
    currs[0] = new Pound();
    currs[1] = new Dollar();

    std::string input;
    std::cout << currs[0]->toString() << " " << currs[1]->toString() << std::endl;
    std::getline(std::cin, input);
    while (input != "q") {
        std::string input_data[4];
        int idx = 0;
        std::string temp;
        // Splitting the input by space after getline() writes to the string
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (c == ' ') {
                input_data[idx++] = temp;
                temp = "";
            } else if (i == input.length() - 1) {
                temp += c;
                input_data[idx++] = temp;
            } else {
                temp += c;
            }
        }

        std::string op = input_data[0];
        std::string firstCurName = input_data[1];
        double amt = std::stod(input_data[2]);
        std::string secondCurName = input_data[3];

        // try catch mechanism to catch and print out exception msgs
        // and prompt for user input.
        try {
            if (firstCurName == "d") {
                if (op == "a") {
                    Dollar other(secondCurName, amt);
                    currs[1]->add(secondCurName, other); 
                } else if (op == "s") {
                    Dollar other(secondCurName, amt);
                    currs[1]->subtract(secondCurName, other);
                }
            } else if (firstCurName == "p") {
                if (op == "a") {
                    Pound other(secondCurName, amt);
                    currs[0]->add(secondCurName, other);
                } else if (op == "s") {
                    Pound other(secondCurName, amt);
                    currs[0]->subtract(secondCurName, other);
                }
            }

            std::cout << currs[0]->toString() << " " << currs[1]->toString() << std::endl;
            std::getline(std::cin, input);
        } catch (std::string& exc) {
            std::cerr << exc << std::endl;
            std::cout << currs[0]->toString() << " " << currs[1]->toString() << std::endl;
            std::getline(std::cin, input);
        }
    }

    delete currs[0];
    delete currs[1];
}