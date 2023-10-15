#include "entry.h"
#include "currency.h";
#include "dollar.h";
#include "cmath"
#include <sstream>
#include <vector>
#include <iomanip>
#define MAX_LOAD_FACTOR 0.6
#define MIN_TABLE_SIZE 10

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #5
 * An implementation of the HashTable ADT with the use of the open-addressing method
 * for collision resolution, and quadratic probing with automatic resizing when
 * the hash table exceeds a LOAD_FACTOR >= MAX_LOAD_FACTOR
 * */
class HashTable {
    private:
        int tableSize;
        int count;
        int collisionCount;
        int m;
        int n;
        int c1 = 1;
        int c2 = 1;

        Entry* hashTable;

        // Hashes the currency using the pseudorandom hash scheme described
        // in the assignment
        int hash(Currency* curr) {
            return m * abs(curr->getCurrencyValue()) + n * abs(curr->getCoinValue());
        }

        // Quadratic probing with constants c1 and c2 set to 1
        int quadProbe(int h, int i) {
            return (h + c1 * i + c2 * i * i) % tableSize;
        }

        // Creates the hash table, setting all entries to empty
        // as there are no keys at the beginning
        void createHashTable(int tableSize) {
            hashTable = new Entry[tableSize];
            for (int i = 0; i < tableSize; i++) {
                hashTable[i] = *(new Entry());    
            }
        }

        // As hash table effectiveness improves with resizing to p
        // when p >= 2 * tableSize, this method functions to check the
        // smallest p such that p >= 2 * tableSize is true.
        bool isPrime(int n) {
            if (n <= 1) {
                return false; 
            }

            int checkLimit = (int) (sqrt(n) + 1);
            for (int i = 2; i < checkLimit; i++) {
                if (n % i == 0) {
                    return false;
                }
            }

            return true;
        }

        // A helper method to resize the hash table when the load factor
        // exceeds 0.6, with resizing being done by iterating over occupied
        // buckets and recalculating hash indices (possibly resorting to quad
        // probing) if there exist collisions, and assigning the new table to
        // the internal hash table.
        void resizeHashTable() {
            int newSize = 2 * tableSize;
            bool isSizePrime = isPrime(newSize);
            while (!isSizePrime) {
                newSize = newSize + 1;
                isSizePrime = isPrime(newSize);
            }

            // Resizes to a size p that is a prime >= 2 * currentSize
            Entry* resizedTable = new Entry[newSize];
            for (int i = 0; i < newSize; i++) {
                resizedTable[i] = *(new Entry());
            }

            for (int i = 0; i < tableSize; i++) {
                Entry e = hashTable[i];
                if (e.type == Occupied) {
                    int probeCount = 0;
                    int keyHash = hash(e.key);
                    int bucketIdx = keyHash % newSize;
                    int collCount = 0;
                    bool isInserted = false;
                    while (probeCount < tableSize && !isInserted) {
                        if (resizedTable[bucketIdx].type == Empty || resizedTable[bucketIdx].type == EmptyAfterRemove) {
                            resizedTable[bucketIdx].key = e.key;
                            resizedTable[bucketIdx].type = Occupied;
                            isInserted = true;
                        } else {
                            collCount++;
                            bucketIdx = quadProbe(keyHash, collCount);
                            probeCount++;
                        }
                    }
                }
            }

            hashTable = resizedTable;
            tableSize = newSize;
        }

    public:
        /**
         * Creates a new hash table with the minimum table size (10)
         * Pre:
         * Post: Sets all values in the hashtable to emptu
        */
        HashTable() {
            this->tableSize = MIN_TABLE_SIZE;
            createHashTable(tableSize);

            m = 2;
            n = 3;
            collisionCount = 0;
        }

        /**
         * Creates a new hash table with the provided table size
         * Pre: tableSize: the size of the hash table to be constructed
         * Post: Sets all values in the hashtable to empty
         * Return:
        */
        HashTable(int tableSize) {
            this->tableSize = tableSize;
            createHashTable(tableSize);

            m = 2;
            n = 3;
            collisionCount = 0;
        }

        /**
         * Inserts the given key into the hashtable with a corresponding entry
         * at an index in the htable. Uses quadratic probing to address collisions.
         * Pre: key: the key to be inserted into the hashtable
         * Post: Inserts the given key into the hashtable, adding an entry in the htable.
         * Return: bool true or false
        */
        bool insert(Currency* key) { 
            int keyHash = hash(key);
            int bucketIdx = keyHash % tableSize;
            int probeCount = 0;
            int i = 0;

            if (getLoadFactor() >= MAX_LOAD_FACTOR) {
                resizeHashTable();
            }

            while (probeCount < tableSize) {
                if (hashTable[bucketIdx].type == Empty || hashTable[bucketIdx].type == EmptyAfterRemove) {
                    hashTable[bucketIdx].key = key;
                    hashTable[bucketIdx].type = Occupied;
                    count = count + 1;
                    return true;
                }

                // Otherwise probe the next table index given by the quadratic
                // probing algorithm
                i = i + 1;
                bucketIdx = quadProbe(keyHash, i);
                probeCount = probeCount + 1;
                collisionCount = collisionCount + 1;
            }

            return false;
        }

        /**
         * Removes the given key from the hashtable with the corresponding entry
         * at an index in the htable. Uses quadratic probing to address collisions.
         * Pre: key: the key to be removed from the hashtable
         * Post: Removes the given key from the hashtable, also removing the entry in the htable.
         * Return: bool true or false
        */
        bool remove(Currency* key) {
            int keyHash = hash(key);
            int bucketIdx = keyHash % tableSize;
            int probeCount = 0;
            int i = 0;

            std::string currType = "dollar";
            while ((probeCount < tableSize) && (hashTable[bucketIdx].type != Empty)) {
                if (hashTable[bucketIdx].type == Occupied && hashTable[bucketIdx].key->isEqual(currType, *key)) {
                    hashTable[bucketIdx].key = NULL;
                    hashTable[bucketIdx].type = EmptyAfterRemove;
                    return true;
                }

                i = i + 1;
                bucketIdx = quadProbe(keyHash, i);
                probeCount = probeCount + 1;
                collisionCount = collisionCount + 1;        
            }

            return false;
        }

        /**
         * Searches the given key in the hashtable with the corresponding entry
         * at an index in the htable. Uses quadratic probing to address collisions.
         * Pre: key: the key to be searched in the hashtable
         * Post: 
         * Return: int -1 if found or integer i >= 0 if found
        */
        int search(Currency* key) {
            int keyHash = hash(key);
            int bucketIdx = keyHash % tableSize;
            int probeCount = 0;
            int i = 0;
            std::string currType = "dollar";
            
            while ((hashTable[bucketIdx].type != Empty) && (probeCount < tableSize)) {
                if (hashTable[bucketIdx].type == Occupied && hashTable[bucketIdx].key->isEqual(currType, *key)) {
                    return bucketIdx;
                }

                i = i + 1;
                bucketIdx = quadProbe(keyHash, i);
                probeCount = probeCount + 1;
                collisionCount = collisionCount + 1;
            }

            return -1;
        }

        /**
         * Checks if a given key exists in the hashtable and maps to
         * a corresponding entry.
         * Pre: key: Currency* key to check for in the table
         * Post:
         * Return: bool true or false
        */
        bool isValidKey(Currency* key) {
            int keyTableIdx = search(key);
            if (keyTableIdx == -1) {
                return false;
            }

            return true;
        }

        /**
         * Collects all keys in the hashtable, returning the pointer
         * to the array containing the keys.
         * Pre:
         * Post:
         * Return: Currency* NULL or array 
        */
        Currency* keys() {
            Currency* keys;
            int keysIdx = 0;

            for (int i = 0; i < tableSize; i++) {
                if (hashTable[i].type == Occupied) {
                    keys[keysIdx] = *(hashTable[i].key);
                }
            }

            return keys;
        }
        
        // temp func
        Currency* getKeyIndex(int idx) {
            return hashTable[idx].key;
        }

        /**
         * Gets the total number of collisions when performing operations
         * on the hashtable
         * Pre:
         * Post:
         * Return: int n (n >= 0)
        */
        int getCollisionCount() {
            return collisionCount;
        }

        /**
         * Gets the load factor, the ratio of the filled buckets to total
         * for use in hashtable resizing operations.
         * on the hashtable
         * Pre:
         * Post:
         * Return: double d (d >= 0.0)
        */
        double getLoadFactor() {
            return ((double) count) / tableSize;
        }

        double getTableSize() {
            return tableSize;
        }

        /**
         * Converts the hashtable into a string representation, displaying
         * the total items, load factor, and the total number of collisions/
         * Pre:
         * Post:
         * Return: std::string "" or a the string
        */
        std::string toString() {
            std::ostringstream oss;
            oss << "Data Items Loaded: " << count << std::endl;
            oss << "Load Factor: " << std::setprecision(3) << getLoadFactor() << std::endl;
            oss << "# of collisions: " << collisionCount << std::endl;
            return oss.str();
        }
};