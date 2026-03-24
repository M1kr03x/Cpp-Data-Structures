#include "../include/OrderedMap.h"
#include <iostream>
int main(){
    OrderedMap map;
    map.insert("Word",4);
    map.insert("Words",5);
    map.insert("Six",3);
    map.insert("Three",5);
    std::cout <<" Map :::: \n";
    map.print();
    map.remove("Word");
    map.print();
    std::cout<<std::endl;
    std::cout<<map.get("Six").value_or(0);
}