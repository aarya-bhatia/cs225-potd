#pragma once

#include <string>

class Food
{
    public:
        Food();
        std::string &get_name();
        void set_name(const std::string &name);
        int get_quantity() const;
        void set_quantity(int quantity);

    private:
        std::string name_;
        int quantity_;
};