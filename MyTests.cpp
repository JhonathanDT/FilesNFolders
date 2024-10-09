#include <iostream>
#include "Folder.hpp"
#include "File.hpp"

int main(){
    int num = 5;
    int* numptr = &num;
    File("jpeg.mafia", "songs written for the album", numptr);
    File();

}