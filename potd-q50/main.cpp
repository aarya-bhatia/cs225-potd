#include <iostream>
#include <string>
#include <vector>
#include "Swiftcipher.h"

int main(int argc, char**argv) {
  std::string s = "";
  if(argc > 1) s = decipherer(argv[1]);
  std::cout << s << std::endl;
	return 0;	
}
