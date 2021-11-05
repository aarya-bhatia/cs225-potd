#include <vector>
#include <string>

using namespace std;

vector<string> NoProblem(int start, vector<int> created, vector<int> needed)
{
    string s1 = "No problem! :D";
    string s2 = "No problem. :(";

    vector<string> out;

    for (int i = 0; i < 12; i++)
    {
        if (i > 0)
        {
            start += created[i - 1];
        }

        std::cout << "Have " << start << " problems at month " << i << std::endl;
        std::cout << "Need " << needed[i] << " problems at month " << i << std::endl;

        if (start >= needed[i])
        {
            start -= needed[i];
            out.push_back(s1);
        }
        else
        {
            out.push_back(s2);
        }
    }

    return out;
}
