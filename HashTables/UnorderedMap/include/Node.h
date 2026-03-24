#ifndef NODE_H
#define NODE_H
#include <memory>
#include <string>
struct Node{
std::string value;
std::string key;
std::unique_ptr<Node> next;
Node(std::string k, std::string v) : value(v), key(k){}
};
#endif