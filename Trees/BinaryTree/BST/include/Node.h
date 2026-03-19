#ifndef NODE_H
#define NODE_H
#include <memory>
struct Node {
	int data;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;
	Node(int data) : data(data), left(nullptr),right(nullptr){}
};
#endif