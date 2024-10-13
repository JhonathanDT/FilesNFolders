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
  /*
   Testing names It WORKS 
  File b ("jpegmafia" , "i forgot my period and my extension");
  // std::cout << b << std::endl;
  File d ("" , "");
  std::cout << d << std::endl;
  File z ( ".txt" , "i got no name before my extension but that's ok");
  std::cout << z << std::endl;
  File p ("." , "i am only a period");
  //  std::cout << p << std::endl;
  File g ("" , "i got no name", bptr);
  File e ("Empty.contents" , ""); //empty contents with a name

  File c ("jpeg.txt" , "i am perfect", aptr); // used for the copy and move assignment
   Testing the Copy Constructor IT WORKS!!
  File copiedFile = c;
  std::cout << "the name of the file is: " << copiedFile.getName() << " \nand the content: " << copiedFile.getContents() <<std::endl;
  // std::cout << "the name of the file is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;

   Testing the Move Constructor 
  File movedFile(std::move(c));
  std::cout << "the name of the moved file is: " << movedFile.getName() << " \nand the content: " << movedFile.getContents() <<std::endl;
  // std::cout << "the name of the file is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;
  

  Testing the Copy Assignment  IT WORKS!!
  //uses the moved file to work the copy assignment
  File copiedAssign ( "something.else", "not important it should contain copied");
  copiedAssign = movedFile;
  std::cout << "the name of the file is: " << copiedAssign.getName() << " \nand the content: " << copiedAssign.getContents() <<std::endl;
  // std::cout << "the name of the file is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;
  

   Testing the Move Assignment  
  File a ("jpegmafia." , "i forgot my extension", bptr);
  File movedAssign ( "something.else", "not important it should be moved");
  movedAssign = std::move(a);
  std::cout << "the name of the movedAssign file is: " << movedAssign.getName() << " \nand the content: " << movedAssign.getContents() <<std::endl;
  std::cout << "the name of the file c is: " << c.getName() << " \nand the content: " << c.getContents() <<std::endl;
  

  int* cptr = movedAssign.getIcon();
  if( cptr == nullptr){
    std::cout<< "the icon is empty" <<std::endl;
  }
  else{
  //show the icon array
  for(int i = 0; i < size; i++){
    std::cout << cptr[i] << " ";
  }
  }
  */
  File c ("jpeg.txt" , "i am perfect", aptr); 
  File likeC ("jpeg.txt" , "i am perfect"); 
  File g ("hello.txt" , "i got no name", bptr);
  File e ("Empty.contents" , ""); 
  Folder first ( "first");
  /* addFile() WORKS!!*/
  first.addFile(c);
  first.addFile(g);
  first.addFile(e);
  /* getSize() WORKS!!*/
  // std::cout << first.getSize() << std::endl;
  
  /* removeFile() WORKS!!*/
  // first.display();
  first.removeFile("txt.hello");
  // first.display();
  first.removeFile("hello.txt");
  // first.display();
  first.removeFile("hello.txt");
  // first.display();
  

  /* moveTo()  IT WORKS!!*/
  /*
  Folder second( "second");
  File cutie( "sabrina.carpenter");
  second.addFile(cutie);
  File cutie2( "sabrina.carpenter");
  first.addFile(cutie2 );
  first.moveFileTo("" , second);
  */

/* copyTo() */
  Folder second( "second");   
  File cutie( "sabrina.carpenter");
  second.addFile(cutie);
  File cutie2( "sabrina.carpenter");
  first.addFile(cutie2 );
  first.display();
  second.display();
  first.copyFileTo("Empty.contents" , second);
  first.display();
  second.display();

}