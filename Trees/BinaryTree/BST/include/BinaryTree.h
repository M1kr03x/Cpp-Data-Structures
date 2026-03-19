#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "Node.h"
#include <optional>
class BinaryTree{
private:
    std::unique_ptr<Node> root;
    void recursivePrint(Node* root);
public:
void print();
void insert(int data);
void findData(int data);
std::optional<int> findMin();
std::optional<int> findMax();

};
#endif