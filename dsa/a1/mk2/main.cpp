#include<iostream>
#include "directed2.hpp"

int main() {
   directed_graph<int> *n = new directed_graph<int>();
   const int e = 3;

   if(n->contains(e)) {
       std::cout << "cheese" << std::endl;
   } 
}