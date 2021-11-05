#include "Pattern.h"
#include <string>
#include <unordered_map>
#include <iostream>

bool wordPattern(std::string pattern, std::string str) {
    std::cout << "Pattern: " << pattern << std::endl;
    std::cout << "String: " << str << std::endl;

    std::unordered_map<std::string, char> words;
    char c = 'a';
    size_t idx = 0;
    std::string next_word = "";

    for(size_t i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ')
        {
            std::cout << "next word: " << next_word << std::endl;

            if(words.find(next_word) == words.end())
            {
                words[next_word] = c++;
            }

            if(pattern[idx++] != words[next_word])
            {
                return false;
            }

            next_word = "";
        }
        else
        {
            next_word += str[i];
        }
    }

    std::cout << "next word: " << next_word << std::endl;

    if(words.find(next_word) == words.end())
    {
        words[next_word] = c++;
    }

    if(pattern[idx++] != words[next_word])
    {
        return false;
    }

    next_word = "";

    return idx >= pattern.length();
}

