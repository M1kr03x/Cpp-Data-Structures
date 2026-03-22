#include "../include/HashTable.h"
#include <iostream>
int HashTable::hashFunction(std::string key){
    int hash = 0;
    for (char c : key){
        hash+=c;
    }
    return hash % TABLE_SIZE;
}
HashTable::HashTable(){
    for(auto& nodes : table){
        nodes = nullptr;
    }
}
void HashTable::insert(std::string key,std::string value){
    int hashed = hashFunction(key);
    Node* newNode = new Node(key,value);
    newNode->next = table[hashed];
    table[hashed] = newNode;
}
std::string HashTable::get(std::string key){
    int hash = hashFunction(key);
    Node* node = table[hash];
    while (node!=nullptr){
        if(node->key == key) return node->value;
        node = node->next;
    }
    return "\nNot found\n";
}
void HashTable::remove(std::string key){
    int hash = hashFunction(key);
    Node* currentNode = table[hash];
    Node* parentNode = nullptr;
    while(currentNode != nullptr){
        if(currentNode->key == key){
            if(parentNode == nullptr){
                table[hash] = currentNode->next;
             
            }
            else{
                parentNode->next = currentNode->next;
               
            }
            delete currentNode;
            return;
        }
        parentNode = currentNode;
        currentNode = currentNode->next;
    }

}
HashTable::~HashTable(){
   for(unsigned i{0};i<TABLE_SIZE;i++){
    Node *currentNode = table[i];
    while(currentNode != nullptr){
        Node* deleteNode = currentNode;
        currentNode = currentNode->next;
        delete deleteNode;
    }
    table[i] = nullptr;
   }
}
void HashTable::print(){
    for(unsigned i{0}; i< TABLE_SIZE;i++){
        std::cout << "Index [" << i <<"]: ";
        Node* currentNode = table[i];
        if(currentNode == nullptr){ std::cout<< "empty"<<std::endl; continue;};
        while(currentNode!=nullptr){
            std::cout<< "["<<currentNode->key <<": " << currentNode->value << "] -> ";
            currentNode = currentNode->next;
            
        }
        std::cout << " nullptr" << std::endl;
    }
}