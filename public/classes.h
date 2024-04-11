//
// Created by OSAMA ASHRAF on 4/11/2024.
//

#ifndef RA7AL_CLASSES_H
#define RA7AL_CLASSES_H
#include <bits/stdc++.h>
using namespace std;

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


    void printItem(int index) {
        auto item = values[index];
        if (holds_alternative<int>(item)) {
            cout << get<int>(item);
        } else if (holds_alternative<double>(item)) {
            cout << get<double>(item);
        } else if (holds_alternative<string>(item)) {
            cout << "\"" << get<string>(item) << "\"";
        } else if (holds_alternative<char>(item)) {
            cout << "\'" << get<char>(item) << "\'";
        } else {
            cout << "Unknown type";
        }
    }


    int size() { return (int) values.size(); }



    /// Iterators
    using iterator = vector<variant<int, double, string, char>>::iterator;

    iterator begin() { return values.begin(); }

    iterator end() { return values.end(); }


    /// Operators
    friend ostream &operator<<(ostream &os, List l) {
        os << '{';
        for (int i = 0; i < l.size(); i++) {
            l.printItem(i);
            os << (i < l.size() - 1 ? ", " : "");
        }

        os << "}";

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
