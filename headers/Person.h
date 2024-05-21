#pragma once
#include <string>
#include <regex>
#include "headers/DataFrame/Case.h"
#include "headers/Budget.h"
using namespace std;

class Person
{
protected:
    static int currentID;
    int id;
    Budget* budget;
    string name;
    string email;
    string password;

public:
    // Default constructor
    Person();

    // Constructor with parameters
    Person(string nameInput, string emailInput, string passwordInput);
    Person(Case& x);

    // Make sure the email is in the correct format
    bool isValidEmail(const string &email) const;

    // Setters
    bool setName(string newName);
    bool setEmail(string newEmail);
    bool setPassword(string newPassword);
    bool setBudget(double amount);

    // Getters
    string getName();
    string getEmail();
    string getPassword();
    double getBudget();
    int getID();


    void printDetails();


    // Destructor
    ~Person(){
        delete budget;
    }
};
