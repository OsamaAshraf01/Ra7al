#pragma once
#include <string>
#include <regex>
using namespace std;

class Person
{
private:
    static int currentID;
    int id;
    string name;
    string email;

public:
    // Default constructor
    Person();

    // Constructor with parameters
    Person(string nameInput, string emailInput);

    // Make sure the email is in the correct format
    bool isValidEmail(const string &email) const;

    // Setters
    void setName(string newName);
    void setEmail(string newEmail);

    // Getters
    string getName();
    string getEmail();

    void printDetails();
};