#include <iostream>
#pragma once

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

class Currency {
    private: 
        int currencyValue;
        int coinValue;

    protected:
        int* convAmount(double amount) {
            int amountCoinValue = (int) (amount * 100);
            int currValue = amountCoinValue / 100;
            int cnValue = amountCoinValue - (currValue * 100);
            int* result = new int[2];
            result[0] = currValue;
            result[1] = cnValue;
            return result;
        }

    public:
        Currency() {
            currencyValue = coinValue = 0;
        }

        Currency(double amount) {
            if (amount < 0) {
                throw "Currency amount cannot be negative";
            }

            int* converted = convAmount(amount);
            currencyValue = converted[0];
            coinValue = converted[1];
        }

        Currency(Currency& other) {
            currencyValue = other.getCurrencyValue();
            coinValue = other.getCoinValue();
        }   

        ~Currency() {}

        /**
         * Returns the integer part n of the total amount of currency stored within
         * this Currency object representing the number of whole denominations for the amount.
         * Pre:
         * Post:
         * Return: int (n >= 0)
        */
        int getCurrencyValue() {
            return currencyValue;
        }        

        /**
         * Returns the fractional part m of the total amount of currency stored within
         * this Currency object as in integer representing the number of coins for the amount.
         * Pre:
         * Post:
         * Return: int (l >= 0)
        */
        int getCoinValue() {
            return coinValue;
        }

        /**
         * Returns a double d that is the total amount of currency stored 
         * within this Currency object. 
         * Pre:
         * Post:
         * Return: double (d >= 0.0)
        */
        double getAmount() {
            return (100.0 * currencyValue + coinValue) / 100.0;
        }

        /**
         * Sets the total amount of currency stored to the new positive
         * Amount A.
         * Pre: amount - a positive double value representing the new amount to be set to.
         * Post:
         * Return: void
        */
        void setCurrency(double amount) {
            int* converted = convAmount(amount);
            currencyValue = converted[0];
            coinValue = converted[1];
        }

        /**
         * Sets the total amount of currency stored to the provided
         * number of whole denominations and number of coins.
         * Pre: currencyValue - a positive integer representing the new number of whole denominations.
         *      coinValue - a positive integer representing the new number of coins.
         * Post:
         * Return: void
        */
        void setCurrency(int currencyValue, int coinValue) {
            this->currencyValue = currencyValue;
            this->coinValue = coinValue; 
        }

       /**
        * Refer to specific subclass Pre/Post documentation for reference.
        **/ 
        virtual void add(std::string& currencyName, Currency& other) = 0;
        
        /**
        * Refer to specific subclass Pre/Post documentation for reference.
        **/ 
        virtual void subtract(std::string& currencyName, Currency& other) = 0;
        
        /**
        * Refer to specific subclass Pre/Post documentation for reference.
        **/ 
        virtual bool isEqual(std::string& currencyName, Currency& other) = 0;
        
        /**
        * Refer to specific subclass Pre/Post documentation for reference.
        **/ 
        virtual bool isGreater(std::string& currencyName, Currency& other) = 0;
        
        /**
        * Refer to specific subclass Pre/Post documentation for reference.
        **/ 
        virtual std::string toString() = 0;
};