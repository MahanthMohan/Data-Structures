#include "currency.h"
#include <string>
#include <sstream>
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
class Pound: public Currency {
    private:
        std::string currencyName;

    public:
        Pound(): Currency(0.0) {
            currencyName = "pound";
        }

        Pound(std::string currencyName, double amount) : Currency(amount) {
            if (currencyName == "pound") {
                this->currencyName = currencyName;
            }
        }
        
        /**
         * Adds the amount of the this pound to the amount stored within
         * the other Currency object if they are of the same type, as specified
         * by the curName string parameter. It then sets the current amount of
         * this instance to the result of the calculation.
         * Pre: curName: string representing the type/name of the other currency
         *      other: reference to another currency object
         * Post: exception string if currencies are not of same type
         * Return: void
        */
        void add(std::string& curName, Currency& other) {
            if (curName != "pound") {
                throw std::string("Invalid addition");     
            }

            double sum = getAmount() + other.getAmount();            
            setCurrency(sum);
        }
         
        /**
         * Subtracts the amount of the this pound to the amount stored within
         * the other Currency object if they are of the same type, as specified
         * by the curName string parameter. It then sets the current amount of
         * this instance to the result of the calculation.
         * Pre: curName: reference to string representing the type/name of the other currency
         *      other: reference to another currency object
         * Post: exception string if currencies are not of same type, or if the
         * other Currency's amount exceeds the amount of this pound.
         * Return: void
        */
        void subtract(std::string& curName, Currency& other) {
            if (curName != "pound") {
                throw std::string("Invalid subtraction");     
            }

            double diff = getAmount() - other.getAmount();
            if (diff < 0) {
                throw std::string("Invalid subtraction");
            }

            setCurrency(diff);

       }

        /**
         * Compares the greater amount of the two Currencies if they are of the same type,
         * as specified by the curName string parameter, returning a boolean of true of false
         * depending on whether this pound's amount is greater than the other.
         * Pre:
         *      curName: reference to string representing the type/name of the other currency.
         *      other: reference to another currency object
         * Post: exception string if currencies are not of same type
         * Return: bool
        */
        bool isGreater(std::string& curName, Currency& other) {
            if (curName != "pound") {
                throw std::string("Invalid comparison (Different Currencies)");
            }

            int totalCoinValue = (100 * getCurrencyValue()) + getCoinValue();
            int otherCoinValue = (100 * other.getCurrencyValue()) + other.getCoinValue();
            return totalCoinValue > otherCoinValue;
        }

        /**
         * Checks if the amount of both currencies are equal or not,
         * returning a boolean of true of false if they are of the same type,
         * as provided by the curName string parameter.
         * Pre:
         *      curName: reference to string representing the type/name of the other currency.
         *      other: reference to another currency object
         * Post: exception string if currencies are not of same type
         * Return: bool
        */
        bool isEqual(std::string& curName, Currency& other) {
            if (curName != "pound") {
                throw std::string("Invalid comparison (Different Currencies)");
            }              
            int totalCoinValue = (100 * getCurrencyValue()) + getCoinValue();
            int otherCoinValue = (100 * other.getCurrencyValue()) + other.getCoinValue();
            return totalCoinValue == otherCoinValue;
        }

        /**
         * Returns the name of this pound, as a string.
         * Pre:
         * Post:
         * Return: std::string
        */
        std::string getCurrencyName() {
            return currencyName;
        } 
        
        /**
         * Formats the fields of this pound in a string format,
         * using the xx.yy format for displaying it, where xx denotes
         * the whole amount and yy the fractional amount (coins).
         * Pre:
         * Return: std::string 
        */
        std::string toString() {
            std::ostringstream oss;
            oss << getCurrencyValue();
            oss << ".";
            oss << getCoinValue();
            oss << " Pound";
            return oss.str();
        }
};