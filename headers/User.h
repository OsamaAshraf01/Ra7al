//
// Created by [] on []
//

#ifndef RA7AL_USER_H
#define RA7AL_USER_H
#include "Person.h"
#include "DataFrame/DataFrame.h"
#include "config.h"

class User : public Person{
public:
    using Person::Person;

    void Register();
};

#endif //RA7AL_USER_H
