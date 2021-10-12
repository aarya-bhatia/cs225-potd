// Animal.h

#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Animal
{
    public:
        Animal();
        Animal(string,string);

        virtual ~Animal();

        string getType() const;
        void setType(string type);
        string getFood() const;
        void setFood(string food);

        virtual string print() const {
            return "I am a " + getType() + ".";
        }

    private:
        string type_;
    
    protected:
        string food_;
};