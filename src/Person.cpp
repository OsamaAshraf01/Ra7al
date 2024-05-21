#include "headers/person.h"
#include "config.h"
#include "headers/DataFrame/DataFrame.h"
#include <iostream>
#include <regex>
using namespace std;

int Person::currentID = 0;

// Default constructor
Person::Person()
{
    DataFrame users(CONFIG.registered_users_table);
    int currentID = get<int>(users[users.size()-1]["ID"]);
    id = currentID+1;
    name = "Unknown";
    password = "";
    email = "N/A";
    budget = new Budget();
}

// Constructor with parameters
Person::Person(string nameInput, string emailInput, string passwordInput)
{
    name = nameInput;
    email = emailInput;
    password = passwordInput;
}

Person::Person(Case &x){
    name = x["Name"].toString();
    password = x["Password"].toString();
    email = x["Email"].toString();
    id = get<int>(x["ID"]);
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
bool Person::setBudget(double amount){
    if(amount < 0)
        return false;

    budget->setBudget(amount);
    return true;
}

// Getters
string Person::getName(){return name;}
string Person::getEmail(){return email;}
string Person::getPassword(){return password;}
double Person::getBudget(){return budget->getTotalBudget();}
int Person::getID(){return id;}


// Methods
void Person::printDetails()
{
    cout << "ID: " << id
         << "\nName: " << name
         << "\nEmail: " << email <<'\n';
}
