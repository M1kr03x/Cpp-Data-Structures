#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "Node.h"
#include <memory>
#include <string>
#include <optional>
class AVLTree{
    private:
    std::unique_ptr<Node> insertRecursive(std::unique_ptr<Node>, const std::string&, int);
    std::optional<int> getHeight(Node*) const;
    int getBalance(Node*) const;
    void updateHeight(Node*);
    std::unique_ptr<Node> rotateLeft(std::unique_ptr<Node>);
    std::unique_ptr<Node> rotateRight(std::unique_ptr<Node>);
    std::optional<std::unique_ptr<Node>> nodeManipulate(std::unique_ptr<Node>);
    int recursive(Node*,int&) const;
    std::unique_ptr<Node> root{nullptr};
    public:
    void insert(const std::string&, int);
    std::optional<int> get(const std::string&) const;
    void remove(const std::string&);
    void print();

};
#endif
