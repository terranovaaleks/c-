#include <utility> // std::pair

#include "hello.h"



int main (int argc, char* argv[]) {  // char* s[]; an array of pointers to char
    
  std::pair<const char*, int> p = parse_args (argc ,argv); //std::make_pair( 2, 3);

  if (p.second != -1)  //p.second  access the element
    hello (p.first, p.second);
}
