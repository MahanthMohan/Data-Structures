#include "currency.h"
#include "dollar.h"
#include <sstream>

/**
 * This type serves to function as the difference between a deleted
 * entry and a forever empty entry, as used in removal and search ops.
*/
enum EntryType {
    Empty,
    EmptyAfterRemove,
    Occupied
};

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #5
 * Represents an entry in the HashTable, with a pointer to the key and the type
 * of the Entry
 * */
class Entry {
    public:
        EntryType type;
        Currency* key;

        /**
         * Constructs a new entry, setting the key to NULL and type to Empty
         * Pre:
         * Post: key set to NULL and type set to Empty
         * Return:
        */
        Entry() {
            key = NULL;
            type = Empty;
        }

        /**
         * Constructs a new entry, setting the key to given key and type to Occupied
         * Pre: key: Currency* key to be set to
         * Post: key set to given key and type set to Occupied
         * Return:
        */
        Entry(Currency* key) {
            this->key = key;
            type = Occupied;
        }

        /**
         * Converts the entry's fields into a string representation.
         * Pre:
         * Post:
         * Return: std::string the string representation of the hashtable entry
        */
        std::string toString() {
            std::ostringstream oss;
            if (type == Occupied) {
                oss << "HashTable Entry:" << std::endl << "key: " << key->toString() << "type: " << type << std::endl;
            } else {
                oss << "HashTable Entry:" << std::endl << "key: NULL" << "type: " << type << std::endl;
            }
            return oss.str();
        }
};