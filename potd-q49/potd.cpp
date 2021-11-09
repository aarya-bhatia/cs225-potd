#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

vector<string> topThree(string filename) {
    string line;
    ifstream infile (filename);
    vector<string> ret;
  
    map<string, int> m;

    if (infile.is_open()) {

        while (getline(infile, line)) {
            if(m.find(line) == m.end())
            {
              m[line] = 1;
            }
            else
            {
              m[line] = m[line] + 1;
            }
        }
    }

    map<string,int>::iterator tmp = m.begin();
    int max = -1;

    for(int i = 0; i < 3; i++)
    {
      for(map<string,int>::iterator it = m.begin(); it != m.end(); ++it)
      {
        if(it->second > max)
        {
          tmp = it;
          max = it->second;
        }
      }

      ret.push_back(tmp->first);
      m.erase(tmp);

      tmp = m.begin();
      max = -1;
    }
  

    infile.close();
    return ret;
}

