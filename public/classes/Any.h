//
// Created by OSAMA ASHRAF on 4/13/2024.
//

#ifndef RA7AL_ANY_H
#define RA7AL_ANY_H
#include <variant>
#include <string>

using namespace std;

class Any : public variant<int, double, string, char>{
};


#endif //RA7AL_ANY_H
