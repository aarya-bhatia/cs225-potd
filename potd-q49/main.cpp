#include "potd.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
  string filename = "in1.txt";	

  vector<string> result = topThree(filename);

  cout << "Result: ";
  for(const string &entry: result)
  {
    cout << entry << " ";;
  }

  cout << endl;

	return 0;
}
