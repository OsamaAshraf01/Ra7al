//
// Created by OSAMA ASHRAF on 4/13/2024.
//

#include "Any.h"


string Any::toString(){
    ostringstream oss;
    if (holds_alternative<int>(*this)) {
        return to_string(get<int>(*this));
    } else if (holds_alternative<double>(*this)) {
        return to_string(get<double>(*this));
    } else if (holds_alternative<string>(*this)) {
        return get<string>(*this);
    } else if (holds_alternative<char>(*this)) {
        oss << get<char>(*this);
        return oss.str();
    } else {
        return "Unknown type";
    }
}