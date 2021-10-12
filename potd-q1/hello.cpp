#include "hello.h"

#include <sstream>

std::string hello(){
    std::string name = "Aarya";
    unsigned int age = 19;

    std::stringstream ss;
    ss << "Hello world! My name is "<< name << " and I am " << age << " years old.";

    return ss.str();
}