#include "Thing.h"

namespace potd
{
        Thing::Thing(int max): props_ct_(0), props_max_(max){
            properties_ = new std::string[max];
            values_ = new std::string[max]; 
        }

        Thing::Thing(const Thing & other) {
            _copy(other);
        }

        Thing &Thing::operator=(const Thing & other) {
            if(this != &other) {
                _destroy();
                _copy(other);
            }

            return *this;
        }

        Thing::~Thing() {
            _destroy();
        }

        /**
         * Takes a property name and value, and inserts them into the arrays. Returns the index into the array if successul, and -1 if the array was full. If the property name already exists, replace the value.
         */
        int Thing::set_property(std::string property, std::string value) {

            // Property exists, then update value at the corresponding index.
            for (int i = 0; i < props_ct_; i++)
            {
                if (properties_[i] == property)
                {
                    values_[i] = value;
                    return i;
                }
            }

            // If property does not exist and there is space in the array,
            // add the new property and value at next available spot.
            if(props_ct_ < props_max_) {
                properties_[props_ct_] = property;
                values_[props_ct_] = value;
                int index = props_ct_;
                props_ct_++;
                return index;
            }

            // Cannot set property...
            return -1;
        }

        /**
         * Returns the corresponding value for a given property name, or else an empty string if that property is not found.
         */
        std::string Thing::get_property(std::string property) {
            for(int i = 0; i < props_ct_; i++) {
                if(properties_[i] == property) {
                    return values_[i];
                }
            }
            return "";
        }


        void Thing::_copy(const Thing & other) {
            props_ct_ = other.props_ct_;
            props_max_ = other.props_max_;
            properties_ = new std::string[props_max_];
            values_ = new std::string[props_max_];
            for(int i = 0; i < props_ct_; i++) {
                properties_[i] = other.properties_[i];
                values_[i] = other.values_[i];
            }
        }

        void Thing::_destroy() {
            delete[] properties_;
            delete[] values_;
        }

}
