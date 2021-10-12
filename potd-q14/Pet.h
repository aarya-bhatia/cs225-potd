// Pet.h

#pragma once

#include "Animal.h"
#include <string>

class Pet: public Animal {
    public:
        Pet();

        Pet(std::string type, std::string food,
        std::string name, std::string owner_name);

        ~Pet();

        std::string getFood();
        void setFood(std::string food);

        const std::string &getName() const;
        void setName(std::string name);

        const std::string &getOwnerName() const;
        void setOwnerName(std::string owner_name);

        inline std::string print() const {
            return "My name is " + getName();
        }

    private:
        std::string name_;
        std::string owner_name_;
};