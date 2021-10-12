#include "Food.h"
#include "q5.h"

#include <iostream>

int main() {
    Food *food = new Food;

    food->set_name(std::string("apples"));
    food->set_quantity(1);

    std::cout << "You have " << food->get_quantity() << " " << food->get_name() << "." << std::endl;

    increase_quantity(food);

    std::cout << "You have " << food->get_quantity() << " " << food->get_name() << "." << std::endl;

    delete food;

    return 0;
}
