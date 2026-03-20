#include "../include/BinaryTree.h"
#include <iostream>
void BinaryTree::recursivePrint(Node* root) {
	if (root == nullptr) return;
	recursivePrint(root->left.get());
	std::cout << root->data << " ";
	recursivePrint(root->right.get());
}
void BinaryTree::print() {
	recursivePrint(root.get());
	std::cout << std::endl;
}
void BinaryTree::insert(int data) {
	if (!root) {
		root = std::make_unique<Node>(data);
		return;
	}
	Node* tempPtr = root.get();
	while (true) {
		if (data < tempPtr->data) {
			if (tempPtr->left == nullptr) {
				tempPtr->left = std::make_unique<Node>(data);
				return;
			}
			tempPtr = tempPtr->left.get();
		}
		else if (data > tempPtr->data) {
			if (tempPtr->right == nullptr) {
				tempPtr->right = std::make_unique<Node>(data);
				return;
			}
			tempPtr = tempPtr->right.get();
		}
	}
	return;
	
}
void BinaryTree::findData(int data) {
	if (!root) {
		std::cout << "Tree does not have root\n";
		return;
	}
	Node* tempPtr = root.get();

	while (tempPtr != nullptr) {
	
			if (tempPtr->data == data) {
				std::cout << "Finded\n";
				return;
			}
			else if (data > tempPtr->data) {
				tempPtr = tempPtr->right.get();
			}
			else if (data < tempPtr->data) {
				tempPtr = tempPtr->left.get();
			}
		}
	std::cout << "Tree does not have " << data;
}
std::optional<int> BinaryTree::findMin() {
if (root == nullptr) return std::nullopt;
Node* tempPtr = root.get();
while (tempPtr->left != nullptr) {
	tempPtr = tempPtr->left.get();
}
return tempPtr->data;
}
std::optional<int> BinaryTree::findMax() {
	if (root == nullptr) return std::nullopt;
	Node* tempPtr = root.get();
	while (tempPtr->right != nullptr) {
		tempPtr = tempPtr->right.get();
	}
	return tempPtr->data;
}
void BinaryTree::remove(int data) {
	Node* parent = nullptr;
	Node* current = root.get();
	while (current and current->data!=data) {
		parent = current;
		if (current->data > data) {
			current = current->left.get();
		}
		if (current->data < data) {
			current = current->right.get();
		}
		if (!current) { std::cout<< "Num doesnt exist"; return; }

	}
	if (current->left == nullptr and current->right == nullptr) {
		if (!parent) root.reset();
		else if (parent->left.get() == current) { parent->left.reset(); return; }
		else { parent->right.reset(); return; }
		return;
	}
	if (current->left != nullptr and current->right==nullptr) {
		if (!parent) root = std::move(current->left);
		else if (parent->left.get() == current) parent->left = std::move(current->left);
		else {
			parent->right = std::move(current->left);
		}
		return;
	}
	if (current->left == nullptr and current->right != nullptr) {
		if (!parent) root = std::move(current->right);
		else if (parent->left.get() == current) {
			parent->left = std::move(current->right);
		}
		else {
			parent->right = std::move(current->right);
		}
		return;
	}
	else{
		current->data = findMinNode(current->right);
		return;
	}
	
}
int BinaryTree::findMinNode(std::unique_ptr<Node>& ptr) {
	Node* parent = nullptr;
	Node* current = ptr.get();
	while (current->left != nullptr) {
		parent = current;
		current = current->left.get();
	}
	int data = current->data;
	if (parent == nullptr) {
		ptr = std::move(current->right);
	}
	else {
		parent->left = std::move(current->right);
	}
	return data;
}