#include "../include/BinaryTree.h"
#include <iostream>
int main(){
BinaryTree tree;
tree.insert(55);
tree.insert(56);
tree.insert(57);
tree.insert(58);
tree.insert(16);
tree.insert(32);
tree.findData(1);
std::optional<int> min = tree.findMin();
std::cout << std::endl << min.value() <<std::endl;
tree.print();
}