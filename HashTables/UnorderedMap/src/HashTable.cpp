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
    std::unique_ptr<Node> node = std::make_unique<Node>(key,value);
    node->next = std::move(table[hashed]);
    table[hashed] = std::move(node);
}
std::string HashTable::get(std::string key){
    int hash = hashFunction(key);
    Node* node = table[hash].get();
    while (node!=nullptr){
        if(node->key == key) return node->value;
        node = node->next.get();
    }
    return "\nNot found\n";
}
void HashTable::remove(std::string key){
    int hash = hashFunction(key);
    Node* currentNode = table[hash].get();
    Node* parentNode = nullptr;
    while(currentNode != nullptr){
        if(currentNode->key == key){
            if(parentNode == nullptr){
                table[hash] = std::move(currentNode->next);
             
            }
            else{
                parentNode->next = std::move(currentNode->next);
               
            }

            return;
        }
        parentNode = currentNode;
        currentNode = currentNode->next.get();
    }

}

void HashTable::print(){
    for(unsigned i{0}; i< TABLE_SIZE;i++){
        std::cout << "Index [" << i <<"]: ";
        Node* currentNode = table[i].get();
        if(currentNode == nullptr){ std::cout<< "empty"<<std::endl; continue;};
        while(currentNode!=nullptr){
            std::cout<< "["<<currentNode->key <<": " << currentNode->value << "] -> ";
            currentNode = currentNode->next.get();
            
        }
        std::cout << " nullptr" << std::endl;
    }
}