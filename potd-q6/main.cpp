#include "q6.h"

#include <iostream>

int main() {
    using namespace potd;

    Student s("Sally", 5);

    std::cout << s.get_name() << " is in grade " << s.get_grade() << "." << std::endl;

    graduate(s);

    std::cout << s.get_name() << " is in grade " << s.get_grade() << "." << std::endl;
}
