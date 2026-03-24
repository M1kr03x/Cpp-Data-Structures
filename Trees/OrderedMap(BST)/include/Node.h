#ifndef NODE_H
#define NODE_H
#include <memory>
#include <string>
struct Node{
    std::unique_ptr<Node> left{nullptr};
    std::unique_ptr<Node> right{nullptr};
    
    int value;
    std::string key;
    Node(std::string key, int value) : key(key), value(value){}
};
#endif