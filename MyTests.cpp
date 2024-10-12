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
  int* bptr; //static memory
  //create an array using dynamic memory allocation
  bptr = new int[size];
  //populating the array
  for(int i = 0; i < size; i++){
    bptr[i] = i+6;
  }
  /* Testing names It WORKS */
  // File a ("jpegmafia." , "i forgot my extension");
  // std::cout << a << std::endl;
  // File b ("jpegmafia" , "i forgot my period and my extension");
  // std::cout << b << std::endl;
  // // File d ("" , "");
  // // std::cout << d << std::endl;
  // File z ( ".txt" , "i got no name before my extension but that's ok");
  // std::cout << z << std::endl;
  // File p ("." , "i am only a period", bptr);
  //  std::cout << p << std::endl;
  // File p ("" , "i got no name", bptr);
  //  std::cout << p << std::endl;
  // File p ("Empty.contents" , "", bptr); //empty contents with a name
  // std::cout << p << std::endl;

  File c ("jpeg.txt" , "i am perfect", aptr); // used for the copy and move assignment
  /** Testing the Copy Constructor IT WORKS!!*/
  /*
  File c ("jpeg.txt" , "i am perfect", aptr);
    std::cout << c << std::endl;
  File copiedFile = c;
  std::cout << "the name of the file is: " << copiedFile.getName() << " \nand the content: " << copiedFile.getContents() <<std::endl;
  std::cout << "the name of the file is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;
  */
  /* Testing the Move Constructor */
  File movedFile(std::move(c));
  std::cout << "the name of the moved file is: " << movedFile.getName() << " \nand the content: " << movedFile.getContents() <<std::endl;
  std::cout << "the name of the file is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;
  

  /* Testing the Copy Assignment  IT WORKS!!*/
  /*
  File copiedAssign ( "something.else", "not important it should contain copied");
  copiedAssign = c;
  std::cout << "the name of the file is: " << copiedAssign.getName() << " \nand the content: " << copiedAssign.getContents() <<std::endl;
  std::cout << "the name of the file is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;
  */

  /* Testing the Move Assignment */
  
  File movedAssign ( "something.else", "not important it should be moved");
  movedAssign = std::move(c);
  std::cout << "the name of the movedAssign file is: " << movedAssign.getName() << " \nand the content: " << movedAssign.getContents() <<std::endl;
  std::cout << "the name of the file c is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;
  

}