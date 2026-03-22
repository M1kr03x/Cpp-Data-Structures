#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
#include <vector>
class HashTable{
    private:
    static const int TABLE_SIZE = 10;
    Node* table[TABLE_SIZE];
    int hashFunction(std::string key);
    public:
    HashTable();
    ~HashTable();
    void insert(std::string, std::string);
    std::string get(std::string);
    void remove(std::string);
    void print();
};
#endif