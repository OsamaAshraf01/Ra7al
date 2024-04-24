#include "../headers/Person.h"
#include <iostream>
#include <regex>
using namespace std;

int Person::currentID = 0;

// Default constructor
Person::Person()
{
    id = currentID++;
    name = "Unknown";
    email = "N/A";
}

// Constructor with parameters
Person::Person(string nameInput, string emailInput)
{
    name = nameInput;
    email = emailInput;
}

// Make sure the email is in the correct format
bool Person::isValidEmail(const string &email) const
{
    const regex emailPattern(R"(^\w+(\[\.-\]?\w+)*@\w+(\[\.-\]?\w+)*(\.\w{2,3})+$)");
    return regex_match(email, emailPattern);
}

// Setters
void Person::setName(string newName) { name = newName; }
void Person::setEmail(string newEmail) { email = newEmail; }

// Getters
int Person::getID() { return id; }
string Person::getName() { return name; }
string Person::getEmail() { return email; }

// Methods
void Person::printDetails()
{
    cout << "ID: " << id
         << "\nName: " << name
         << "\nEmail: " << email << '\n';
}