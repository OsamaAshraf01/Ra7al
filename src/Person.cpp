#include "headers/person.h"
#include <iostream>
#include <regex>
using namespace std;

int Person::currentID = 0;

// Default constructor
Person::Person()
{
    id = currentID++;
    name = "Unknown";
    password = "";
    email = "N/A";
}

// Constructor with parameters
Person::Person(string nameInput, string emailInput, string passwordInput)
{
    name = nameInput;
    email = emailInput;
    password = passwordInput;
}

// Make sure the email is in the correct format
bool Person::isValidEmail(const string &email) const
{
    const regex emailPattern(R"(^\w+(\[\.-\]?\w+)*@\w+(\[\.-\]?\w+)*(\.\w{2,3})+$)");
    return regex_match(email, emailPattern);
}

// Setters
bool Person::setName(string newName){
    if(!newName.empty()){
        name = newName;
        return true;
    }

    return false;
}
bool Person::setEmail(string newEmail){
    if(isValidEmail(newEmail)){
        email = newEmail;
        return true;
    }

    return false;
}

bool Person::setPassword(string newPassword){
    // TODO: Password Validation

    if(!newPassword.empty()){
        password = newPassword;
        return true;
    }

    return false;
}

// Getters
string Person::getName(){return name;}
string Person::getEmail(){return email;}
string Person::getPassword(){return password;}


// Methods
void Person::printDetails()
{
    cout << "ID: " << id
         << "\nName: " << name
         << "\nEmail: " << email <<'\n';
}
