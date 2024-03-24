#include <iostream>
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
    Person()
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
    Person(int ageInput, string sexInput, int budgetInput, string nameInput, string emailInput, string addressInput, string phoneNumberInput)
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
    bool isValidEmail(const string &email) const
    {
        const regex emailPattern(R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)");
        return regex_match(email, emailPattern);
    }

    // Setters
    void setAge(int newAge){age = newAge;}

    void setSex(string newSex){sex = newSex;}

    void setBudget(int newBudget){budget = newBudget;}

    void setName(string newName){name = newName;}

    void setEmail(string newEmail){email = newEmail;}

    void setAddress(string newAddress){address = newAddress;}

    void setPhoneNumber(string newPhoneNumber){phoneNumber = newPhoneNumber;}

    // Getters
    int getID()
    {
        return id;
    }

    int getAge()
    {
        return age;
    }

    string getSex()
    {
        return sex;
    }

    int getBudget()
    {
        return budget;
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }

    string getAddress()
    {
        return address;
    }

    string getPhoneNumber()
    {
        return phoneNumber;
    }

    void printDetails()
    {
        cout << "ID: " << id << "\nAge: " << age << "\nSex: " << sex << "\nBudget: " << budget << "\nName: " << name << "\nEmail: " << email;
        cout << "\nAddress: " << address << "\nPhone Number: " << phoneNumber << endl;
    }
};
