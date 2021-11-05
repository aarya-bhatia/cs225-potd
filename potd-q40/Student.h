#pragma once

#include <string>

class Student {
    public:
        Student(int anticipatedTimeNeeded, std::string questionType, const char *name = "");
        int getTimeNeeded();
        std::string getQuestionType();

        const char *name;

    private:
        int anticipatedTime;
        std::string qType;
};
