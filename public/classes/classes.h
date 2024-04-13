//
// Created by OSAMA ASHRAF on 4/11/2024.
//

#ifndef RA7AL_CLASSES_H
#define RA7AL_CLASSES_H
#include <bits/stdc++.h>
using namespace std;

// TODO: Create Any or list_item class to handle printing and adding elements of lists
/*=====List Example========
    List l1, l2, l3;
    l1 = {"osama", 45, 98.5, 'A'};
    l1.append(14.5);
    l1.append("Ahmed");


    l2 = {14, 89.4, "Omar"};


    l3 = l1 + l2;
    cout<<l3;
 */
//=====List definition=====
class List {
private:
    vector<variant<int, double, string, char> > values;
public:
    /// Constructor
    template<typename... Args>
    List(Args... args) {
        initialize(args...);
    }

    template<typename T, typename... Args>
    void initialize(T first, Args... rest) {
        values.emplace_back(first);
        initialize(rest...);
    }

    // Base Case
    void initialize() {}


    /// Methods
    void append(const variant<int, double, string, char> &e) {
        values.emplace_back(e);
    }


    string getItem(int index) {
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


    string toString() {
        ostringstream oss;
        oss << '{';
        for (int i = 0; i < size(); i++) {
            oss << getItem(i);
            oss << (i < size() - 1 ? ", " : "");
        }

        oss << "}";


        return oss.str();
    }


    int size() { return (int) values.size(); }



    /// Iterators
    using iterator = vector<variant<int, double, string, char>>::iterator;

    iterator begin() { return values.begin(); }

    iterator end() { return values.end(); }


    /// Operators
    friend ostream &operator<<(ostream &os, List l) {
        os << l.toString();
        return os;
    }

    List operator+(List &other) {
        List temp = *this;
        for (const auto &e: other) {
            temp.values.emplace_back(e);
        }

        return temp;
    }

    auto operator[](int index) { return values[index]; }

};


#endif //RA7AL_CLASSES_H
