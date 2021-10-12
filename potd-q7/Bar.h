#pragma once

#include "Foo.h"

namespace potd {

    class Bar {
        public:
            Bar(std::string);
            Bar(const Bar &);
            ~Bar();
            Bar &operator=(const Bar &);
            std::string get_name() const;

        private:
            Foo *f_;
    };
 
}