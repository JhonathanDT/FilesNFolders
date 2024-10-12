#include <iostream>
#include "Folder.hpp"

int main(){
  
  int size = 256;
  int* aptr; //static memory
  //create an array using dynamic memory allocation
  aptr = new int[size];
  //populating the array
  for(int i = 0; i < size; i++){
    aptr[i] = i+5;
  }
  
  // File a ("jpegmafia." , "hello there");
  // std::cout << a << std::endl;
  // File b ("jpegmafia" , "hello there");
  // std::cout << b << std::endl;
  // File d ("" , "");
  // std::cout << d << std::endl;
  // File b ( ".txt" , "hi budddy");
  // std::cout << b << std::endl;
  File c ("jpeg.txt" , "i am not empty", aptr);
   std::cout << c << std::endl;


}