#ifndef ORDERED_MAP_H
#define ORDERED_MAP_H
#include "Node.h"
#include <memory>
#include <string>
#include <optional>
class OrderedMap{
    private:
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
