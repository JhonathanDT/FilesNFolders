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

std::ostream& operator<< (std::ostream& os, const File& target) {
   os << "Name: " << target.getName() << std::endl;
   os << "Size: " << target.getSize() << " bytes" << std::endl;
   os << "Contents: " << target.getContents(); 
   return os;
}

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

 /**
      * @brief Constructs a new File object.
      * 
      * @param filename A const reference to a string containing alphanumeric characters and exactly one period in the format "filename" or "filename.extension"
      *    - If the string contains any non-alphanumeric characters besides *exactly_one* period an InvalidFormatException is thrown
      *    - If no extension is provided (e.g. there is no period within the provided filename) or nothing follows the period, then ".txt" is used as the extension
      *    - Default value of "NewFile.txt" if none provided or if filename is empty 
      * @param contents A string representing the contents of the file. Default to empty string if none provided.
      * @param icon A pointer to an integer array with length ICON_DIM. Default to nullptr if none provided.
      * @throws InvalidFormatException - An error that occurs if the filename is not valid by the above constraints.
      * @note You'll notice we provide a default value for the first possible argument (filename)
      *       Yes, this means we can define override the default constructor and define a parameterized one simultaneously.
      */
File::File(const std::string& filename, const std::string& contents, int* icon) : filename_("NewFile.txt"), contents_(""), icon_(nullptr){

   //nothing has to be done for the contents 
   //check icon is good
   icon_ = nullptr;
   setIcon(icon);

   contents_ = contents;

   if(filename.empty() ) { return; }

   if(filename == "."){
      filename_ = filename;
      return;
   }
  
   //check if the filename is good
   std::string::const_iterator it = filename.cbegin();
   int periodFound_ = 0;
   //this while loop will only be used to check all the letters up until it sees a period(if it finds one)
   while( it != filename.cend()){
      //if the character we are on is not an alphanumeric we go in this if statement 
      if( !std::isalnum(*it)){
         // if the character is a period we have reached the extension part
         if( *it == '.'){
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
  
   if( periodFound_ == 1){
      //run through the remaining string to see if it is alnum
      for( const char& c : filename.substr( filename.find('.')+1 )){
         if(!std::isalnum(c)){
            throw InvalidFormatException("Invalid file name: " + filename);
         }
      }
      filename_ = filename;
      std::cout << "only one . was found and alnum was good after that 1 period" << std::endl;
   }
   else{
      filename_ = filename + ".txt";
   }

   if( filename_.find('.') == filename_.length()-1){
      filename_ += "txt";
   }

   std::cout<< "constructor invoked" <<std::endl;
}

std::size_t File::getSize() const{
   //each char has the size of 1 byte so using .size on contents_ = the size in bytes
   return contents_.size();

}

//copy constructor
File::File(const File& other) : filename_{other.filename_}, contents_{other.contents_}{
   icon_ = new int[ICON_DIM];
   for(int i = 0; i < ICON_DIM; i++){
      icon_[i] = other.icon_[i];
   }
   std::cout<< "Copy constructor invoked" << std::endl; 
}

File& File::operator=( const File& other){
   //if the File object we are copying is not the same object we have right now 
   // delete the current data and deep copy the data from the other 
   if(this != &other) {
      delete[] icon_;
      icon_ = nullptr;
      filename_ = other.filename_;
      contents_ = other.contents_;
      icon_ = new int[ICON_DIM];
      for( int i = 0; i < ICON_DIM; i++){
         icon_[i] = other.icon_[i];
      }
   }
   std::cout << "Copy assignment operator invoked" << std::endl;
   return *this;
}

File::File(File&& other) : filename_{other.filename_}, contents_{other.contents_} {
   other.icon_ = nullptr;
   other.filename_ = "";
   other.contents_ = "";
   std::cout << "Move constructor invoked" <<std::endl;
}

File& File::operator=(File&& other){
   //if the object being moved is not the same then 
   //delete the current data and shallow copy the data from the other
   if(this != &other) {
      delete[] icon_;
      filename_ = other.filename_;
      contents_ = other.contents_;
      icon_ = other.icon_;
      other.icon_ = nullptr;
   }
   std::cout << "Move assignment operator invoked" << std::endl;
   return *this;
}

File::~File() { 
   delete[] icon_;
   icon_ = nullptr;
   std::cout << "destructor invoked"<<std::endl;
}