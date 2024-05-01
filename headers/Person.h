#pragma once
#include <string>
#include <regex>
using namespace std;

class Person
{
protected:
    static int currentID;
    int id;
    string name;
    string email;
    string password;

public:
    // Default constructor
    Person();

    // Constructor with parameters
    Person(string nameInput, string emailInput, string passwordInput);

    // Make sure the email is in the correct format
    bool isValidEmail(const string &email) const;

    // Setters
    bool setName(string newName);
    bool setEmail(string newEmail);
    bool setPassword(string newPassword);

    // Getters
    int getID();
    string getName();
    string getEmail();
    string getPassword();

    void printDetails();
};
