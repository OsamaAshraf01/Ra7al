#pragma once
#include <string>
#include <regex>
using namespace std;

class Person
{
private:
    static int currentID;
    int id;
    int age;
    string sex;
    int budget;
    string name;
    string email;
    string address;
    string phoneNumber;

public:
    // Default constructor
    Person();

    // Constructor with parameters
    Person(int ageInput, string sexInput, int budgetInput, string nameInput, string emailInput, string addressInput, string phoneNumberInput);

    // Make sure the email is in the correct format
    bool isValidEmail(const string &email) const;

    // Setters
    void setAge(int newAge);
    void setSex(string newSex);
    void setBudget(int newBudget);
    void setName(string newName);
    void setEmail(string newEmail);
    void setAddress(string newAddress);
    void setPhoneNumber(string newPhoneNumber);

    // Getters
    int getID();
    int getAge();
    string getSex();
    int getBudget();
    string getName();
    string getEmail();
    string getAddress();
    string getPhoneNumber();

    void printDetails();
};