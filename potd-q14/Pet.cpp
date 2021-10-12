// Pet.cpp

#include "Pet.h"

Pet::Pet(): Animal("cat", "fish"), name_("Fluffy"), owner_name_("Cinda") {
}

Pet::Pet(std::string type, std::string food, std::string name, std::string owner_name): Animal(type, food), name_(name), owner_name_(owner_name) {
}

Pet::~Pet() {}

const std::string &Pet::getName() const {
    return name_;
}

const std::string &Pet::getOwnerName() const {
    return owner_name_;
}

std::string Pet::getFood() {
    return Animal::getFood();
}

void Pet::setFood(std::string food) {
    Animal::setFood(food);
}

void Pet::setName(std::string name) {
    name_ = name;
}

void Pet::setOwnerName(std::string owner_name) {
    owner_name_ = owner_name;
}