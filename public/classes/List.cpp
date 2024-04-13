//
// Created by OSAMA ASHRAF on 4/13/2024.
//

#include "List.h"
#include <bits/stdc++.h>
using namespace std;


/// Methods
void List::append(Any e) {
    values.emplace_back(e);
}


string List::getItem(int index) {
    ostringstream oss;
    auto item = values[index];
    if (holds_alternative<int>(item)) {
        return to_string(get<int>(item));
    } else if (holds_alternative<double>(item)) {
        return to_string(get<double>(item));
    } else if (holds_alternative<string>(item)) {
        return get<string>(item);
    } else if (holds_alternative<char>(item)) {
        oss << get<char>(item);
        return oss.str();
    } else {
        return "Unknown type";
    }
}


int List::size() { return (int) values.size(); }


string List::toString() {
    ostringstream oss;
    oss << '{';
    for (int i = 0; i < size(); i++) {
        oss << getItem(i);
        oss << (i < size() - 1 ? ", " : "");
    }

    oss << "}";


    return oss.str();
}






/// Iterators
using Iterator = vector<Any>::iterator;

Iterator List::begin() { return values.begin(); }

Iterator List::end() { return values.end(); }


/// Operators
ostream& operator<<(ostream &os, List l) {
    os << l.toString();
    return os;
}

List List::operator+(List &other) {
    List temp = *this;
    for (const auto &e: other) {
        temp.values.emplace_back(e);
    }

    return temp;
}

Any& List::operator[](int index) { return values[index]; }