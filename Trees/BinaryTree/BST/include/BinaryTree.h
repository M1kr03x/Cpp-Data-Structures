#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "Node.h"
#include <optional>
class BinaryTree{
private:
    std::unique_ptr<Node> root;
    void recursivePrint(Node*);
public:
void print();
void insert(int);
void findData(int);
std::optional<int> findMin();
std::optional<int> findMax();
void remove(int);
int findMinNode(std::unique_ptr<Node>&);
};
#endif