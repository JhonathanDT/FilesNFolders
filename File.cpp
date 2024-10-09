#include "File.hpp"
      
std::string File::getName() const {
   return filename_;
}

std::string File::getContents() const {
   return contents_;
}

void File::setContents(const std::string& new_contents) {
   contents_ = new_contents;
}

int* File::getIcon() const {
   return icon_;
}

void File::setIcon(int* new_icon) {
   if (icon_) { delete[] icon_; }
   icon_ = new_icon;
} 

// std::ostream& operator<< (std::ostream& os, const File& target) {
//    os << "Name: " << target.getName() << std::endl;
//    os << "Size: " << target.getSize() << " bytes" << std::endl;
//    os << "Contents: " << target.getContents(); 
//    return os;
// }

bool File::operator<(const File& rhs) const {
   return getName() < rhs.getName();
}

//                       DO NOT EDIT ABOVE THIS LINE. 
//             (unless you want your work to be tested incorrectly)
//    That also means includes. Remember, all other includes go in .hpp

// However, you may notice an operator overload you don't recognize (<<)
// Try calling the following once you've implemented a constructor & getSize():
//    File a; 
//    std::cout << a << std::endl;

// =========================== YOUR CODE HERE ===========================
File::File(const std::string& filename, const std::string& contents, int* icon) : filename_("NewFile.txt"), contents_(""), icon_(nullptr){

    //we can not have the first character in the filename be a period
   if( filename[0] == '.'){
      throw InvalidFormatException("Invalid file name: " + filename);
   }
   //check if the filename is good
   std::string::const_iterator it = filename.cbegin();
   int periodFound_ = 0;
   //this while loop will only be used to check all the letters up until it sees a period(if it finds one)
   while( it != filename.cend()){
      //if the character we are on is not an alphanumeric we go in this if statement 
      if( !std::isalnum(*it)){
         // if the character is a period we have reached the extension part
         if( *it == "."){
            //we have reached the extension
            //raise a counter saying we have our "." 1
            periodFound_++;
            //end this while loop
            break;
         }
         // else it is something else and we break out and throw the exception 
         else{
            throw InvalidFormatException("Invalid file name: " + filename);
         }
      }
      it++;
   }
   // if no period was found add ".txt" to the end 
   if(periodFound_ == 0){
      filename_ = filename + ".txt";
   }
   else if( periodFound_ == 1){
      //run through the remaining string to see if it is alnum
      for( const char& c : filename.substr( filename.find('.')+1 )){
         if(!std::isalnum(c)){
            throw InvalidFormatException("Invalid file name: " + filename);
         }
      }
   }
   //if we have more than one period this is an invalid file Name
   else( periodFound_ > 1){
      throw InvalidFormatException("Invalid file name: " + filename);
   }

   //check if the contents name is good

   //check icon is good
}