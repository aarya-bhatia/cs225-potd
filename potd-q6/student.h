#pragma once

#include <string>

namespace potd {
    class Student {
        public:
            Student(): name_(std::string()), grade_(1) {}
            Student(const std::string &name, int grade): name_(name), grade_(grade) {}

            const std::string& get_name() const { return name_; }
            void set_name(const std::string &name) { name_ = name; }

            int get_grade() const { return grade_; }
            void set_grade(int grade) { grade_ = grade; }
            
        private:
            std::string name_;
            int grade_;
    };
}