#include "../include/User.h"
#include <iostream>
#include <string>
#include <regex>
using namespace std;

User::User()
{
    email = "";
    password = "";
    itineraries = {};
    payments = {};
    budget = Budget();
    preferences = {};
    language = Language();
}

User::User(string email, string password, vector<Itinerary> itineraries, vector<PaymentMethod> payments, Budget budget, vector<string> preferences, Language language)
{
    if (validEmail(email))
    {
        cout << "Email is valid" << endl;
    }
    else
    {
        cout << "Email is invalid" << endl;
        return;
    }

    this->email = email;
    this->password = password;
    this->itineraries = itineraries;
    this->payments = payments;
    this->budget = budget;
    this->language = language;
    this->preferences = preferences;
}

void User::addItinerary(Itinerary newItinerary)
{
    itineraries.push_back(newItinerary);
}

void User::addPaymentMethod(PaymentMethod newPayment)
{
    payments.push_back(newPayment);
}

void User::setBudget(Budget newBudget)
{
    budget = newBudget;
}

void User::addLanguage(Language newLanguage)
{
    language = newLanguage;
}

vector<Itinerary> User::getItineraries()
{
    return itineraries;
}

vector<PaymentMethod> User::getPaymentMethods()
{
    return payments;
}

Budget User::getBudget()
{
    return budget;
}

Language User::getLanguage()
{
    return language;
}

void User::showPreferences()
{
    for (int i = 0; i < preferences.size(); i++)
    {
        cout << preferences[i] << endl;
    }
}

void User::printDetails()
{
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
    cout << "Itineraries: " << endl;
    for (int i = 0; i < itineraries.size(); i++)
    {
        cout << itineraries[i].show() << endl;
    }
    cout << "Payments: " << endl;
    for (int i = 0; i < payments.size(); i++)
    {
        cout << payments[i].getCardNumber() << endl; // to be implemented
    }
    cout << "Budget: " << budget.overview() << endl;
    cout << "Language: " << language.getLanguage() << endl;
    cout << "Preferences: " << endl;
    for (int i = 0; i < preferences.size(); i++)
    {
        cout << preferences[i] << endl;
    }
}