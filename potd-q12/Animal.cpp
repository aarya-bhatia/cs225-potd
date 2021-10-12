// Animal.cpp

#include "Animal.h"

Animal::Animal(): type_("cat"), food_("fish")
{

}

Animal::Animal(string type, string food):
    type_(type),
    food_(food)
{
    
}

Animal::~Animal() {

}

string Animal::getType() const {
    return type_;
}

string Animal::getFood() const {
    return food_;
}

void Animal::setType(string type) {
    type_ = type;
}

void Animal::setFood(string food) {
    food_ = food;
}
