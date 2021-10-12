#include "Bar.h"

namespace potd {

    Bar::Bar(std::string name) {
        f_ = new Foo(name);
    }

    Bar::~Bar() {
        delete f_;
    }

    Bar::Bar(const Bar &other) {
        f_ = new Foo(*other.f_);
    }

    Bar &Bar::operator=(const Bar &other) {
        if(this != &other) {
            delete f_;
            f_ = new Foo(*other.f_);
        }

        return *this;
    }

    std::string Bar::get_name() const {
        return f_->get_name();
    }

}