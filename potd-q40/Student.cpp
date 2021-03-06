#include "Student.h"

Student::Student(int anticipatedTimeNeeded, std::string questionType,
const char *name): name(name) {
  anticipatedTime = anticipatedTimeNeeded;
  qType = questionType;
}

int Student::getTimeNeeded() {
    return anticipatedTime;
}

std::string Student::getQuestionType() {
    return qType;
}
