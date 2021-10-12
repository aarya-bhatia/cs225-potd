#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Bracket
{
  public:
  static unordered_map<char,char> &Get(){
    if(!brackets) {
      init();
    }
    return *brackets;
  }

  static bool isBracket(char c)
  {
    return Get().find(c) != Get().end();
  }

  static bool isPair(char c1, char c2)
  {
    return Get()[c1] == c2 && Get()[c2] == c1;
  }

  static bool isOpenBracket(char c)
  {
    return c == '(' || c == '{' || c == '[';
  }

  static bool isCloseBracket(char c)
  {
    return c == ')' || c == '}' || c == ']';
  }


  private:

  static void init() {
    brackets = new unordered_map<char, char>;
  
    (*brackets)['('] = ')';
    (*brackets)[')'] = '(';
    (*brackets)['{'] = '}';
    (*brackets)['}'] = '{';
    (*brackets)['['] = ']';
    (*brackets)[']'] = '[';
  }

  static unordered_map<char,char> *brackets; 
};

unordered_map<char, char> *Bracket::brackets = nullptr;

bool isValid(string input) {
    stack<char> st;

    for(size_t i = 0; i < input.size(); i++) 
    {
      char c = input[i];
      if(Bracket::isOpenBracket(c)) 
      {
        st.push(c);
      }
      else if(Bracket::isCloseBracket(c))
      {
        /**
         * if current bracket is a closing bracket,
         * then the top element of the stack
         * has to be the corresponding opening bracket
         * otherwise expression is illegal.
         */

         if(!st.empty() && Bracket::isPair(st.top(), c)) {
           st.pop();
         } else {
           return false;
         }
      }
    }


    return st.empty();
}
