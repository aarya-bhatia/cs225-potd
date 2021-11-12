#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
  map<string, int> m;
  int t = 0;

  string line;
  ifstream myfile(filename);
  if(myfile.is_open())
  {
    while(getline(myfile, line))
    {
      if(m.find(line) == m.end())
      {
        m[line] = 0;
        t++;
      }
      else 
      {
        m[line]++;
      }
    }

    myfile.close();
  }

  vector<string> v(t);

  for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
  {
    v[it->second] = it->first;
  }

  stringstream ss;

  for(vector<string>::iterator it = v.begin(); it != v.end(); it++)
  {
    ss << *it << " ";
  }

	string r = ss.str();
  return r.substr(0, r.length()-1);
}
