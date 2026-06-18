  
  
  #include <iostream>
#include <algorithm>  // for reverse()

int main() {
    std::string str = "Hello, World!",copy_str;
    
    // Using reverse function from algorithm
    copy_str =str;
    std::reverse(str.begin(), str.end());
    
    std::cout << "Reversed string: " << copy_str << std::endl;

    return 0;
}  