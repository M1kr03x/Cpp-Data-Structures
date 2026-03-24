#include "../include/OrderedMap.h"
#include <iostream>

void OrderedMap::insert(const std::string&key,int value){
if(root == nullptr){
root = std::make_unique<Node>(key,value);
return;
}   
Node* tempNode = root.get();

while(true){
    if(tempNode->key > key){
        if(tempNode->left == nullptr){
            tempNode->left = std::make_unique<Node>(key,value);
            return;
        }
        else {
            tempNode = tempNode->left.get();
        }
    }
     else if(tempNode->key < key){
        if(tempNode->right == nullptr){
            tempNode->right = std::make_unique<Node>(key,value);
            return;
        }
        else{
            tempNode = tempNode->right.get();
        }
     }
     else{
        std::cout << "Item already exists\n";
        return;
     }
}
}
std::optional<int> OrderedMap::get(const std::string& key) const{
    if(root == nullptr) return std::nullopt;
    Node* tempNode = root.get();
   while(tempNode!=nullptr){
        if(tempNode->key == key) return tempNode->value;
        if(key>tempNode->key){
            tempNode = tempNode->right.get();
        } 
        else{
            tempNode = tempNode->left.get();
        }
   }

return std::nullopt;
}


std::optional<std::unique_ptr<Node>> OrderedMap::nodeManipulate(std::unique_ptr<Node> node){
    if(node->right == nullptr and node->left == nullptr){
        return std::nullopt;
    }
    if(node->right == nullptr and node->left != nullptr){
        return std::move(node->left);
    }
    if(node->right != nullptr and node->left == nullptr){
        return std::move(node->right);       
    }
    else{
        Node*tempNode = node.get();
        Node* parentNode = tempNode;
        Node* successor = tempNode->right.get();
        while(successor->left!=nullptr){
            parentNode = successor;
            successor = successor->left.get();
        }
        tempNode->key = successor->key;
        tempNode->value = successor->value;
        if(parentNode == tempNode){
            tempNode->right = std::move(successor->right);
        }
        else{
            parentNode->left = std::move(successor->right);
        }
        return std::move(node);
    }
}

void OrderedMap::remove(const std::string&key){

    if(root == nullptr) return;
    Node* tempNode = root.get();
    Node* parentNode = nullptr;
    if (root->key == key) {
    auto ptr = nodeManipulate(std::move(root));
    if (ptr != std::nullopt) root = std::move(ptr.value());
    else root.reset();
    return;
    }    
    while(tempNode!=nullptr){
        if(tempNode->key == key){
           if(parentNode->left.get() == tempNode){
            std::optional<std::unique_ptr<Node>>ptr= nodeManipulate(std::move(parentNode->left));
            if(ptr!=std::nullopt)
            parentNode->left = std::move(ptr.value());
            return;
           }
           else if(parentNode->right.get() == tempNode){
             std::optional<std::unique_ptr<Node>>ptr= nodeManipulate(std::move(parentNode->right));
             if(ptr!=std::nullopt)
            parentNode->right = std::move(ptr.value());
            return;
           }
        }
        if(key>tempNode->key){
            parentNode = tempNode;
            tempNode = tempNode->right.get();
        } 
        else{
             parentNode = tempNode;
            tempNode = tempNode->left.get();
        }       
    }
    return;
}
int OrderedMap::recursive(Node* node,int& counter) const{
    if (node == nullptr) {
        return 0; 
    }
    int leftCount = recursive(node->left.get(), counter);
    counter++; 
    std::cout << "Node #" << counter << " | Key: " << node->key << " | Value: " << node->value <<std::endl;
    int rightCount = recursive(node->right.get(), counter);
    return 1 + leftCount + rightCount;
}
void OrderedMap::print(){
    int counter{0};
    recursive(root.get(),counter);
}