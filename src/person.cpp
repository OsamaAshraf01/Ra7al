#include "../include/person.hpp"
#include <iostream>
#include <regex>
using namespace std;

int Person::currentID = 0;

// Default constructor
Person::Person()
{
    id = currentID++;
    age = 0;
    sex = "N/A";
    budget = 0;
    name = "Unknown";
    email = "N/A";
    address = "N/A";
    phoneNumber = "N/A";
}

// Constructor with parameters
Person::Person(int ageInput, string sexInput, int budgetInput, string nameInput, string emailInput, string addressInput, string phoneNumberInput)
{
    id = currentID++;
    age = ageInput;
    sex = sexInput;
    budget = budgetInput;
    name = nameInput;
    email = emailInput;
    address = addressInput;
    phoneNumber = phoneNumberInput;
}

// Make sure the email is in the correct format
bool Person::isValidEmail(const string &email) const
{
    const regex emailPattern(R"(^\w+(\[\.-\]?\w+)*@\w+(\[\.-\]?\w+)*(\.\w{2,3})+$)");
    return regex_match(email, emailPattern);
}

// Setters
void Person::setAge(int newAge)
{
    age = newAge;
}

void Person::setSex(string newSex)
{
    sex = newSex;
}

void Person::setBudget(int newBudget)
{
    budget = newBudget;
}

void Person::setName(string newName)
{
    name = newName;
}

void Person::setEmail(string newEmail)
{
    email = newEmail;
}

void Person::setAddress(string newAddress)
{
    address = newAddress;
}

void Person::setPhoneNumber(string newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

// Getters
int Person::getID()
{
    return id;
}

int Person::getAge()
{
    return age;
}

string Person::getSex()
{
    return sex;
}

int Person::getBudget()
{
    return budget;
}

string Person::getName()
{
    return name;
}

string Person::getEmail()
{
    return email;
}

string Person::getAddress()
{
    return address;
}

string Person::getPhoneNumber()
{
    return phoneNumber;
}

void Person::printDetails()
{
    cout << "ID: " << id << "\nAge: " << age << "\nSex: " << sex << "\nBudget: " << budget << "\nName: " << name << "\nEmail: " << email;
    cout << "\nAddress: " << address << "\nPhone Number: " << phoneNumber << endl;
}