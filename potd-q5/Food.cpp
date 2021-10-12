#include "Food.h"

Food::Food(): name_(std::string()), quantity_(0)
{
}

std::string &Food::get_name()
{
    return name_;
}

void Food::set_name(const std::string &name)
{
    name_ = name;
}

int Food::get_quantity() const
{
    return quantity_;
}

void Food::set_quantity(int quantity)
{
    quantity_ = quantity;
}