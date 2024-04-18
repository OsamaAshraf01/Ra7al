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
    this->preferences = preferences;
    this->language = language;
}

void User::login(string email, string password)
{
    // to be implemented when database is ready
    // verify email and password
    // if valid, set user as logged in
    // else, show error message
}

void User::logout()
{
    // to be implemented when database is ready
    // set user as logged out
}

bool User::isLogged()
{
    // to be implemented when database is ready
    // check if user is logged in
}

bool User::validEmail(string email)
{
    static const std::regex email_regex(R"([a-zA-Z0-9\._%+\-]+@[a-zA-Z0-9\.\-]+\.[a-zA-Z]{2,})"); // regex for email
    return regex_match(email, email_regex);
}

void User::showPreferences()
{
    for (int i = 0; i < preferences.size(); i++)
    {
        cout << preferences[i] << endl;
    }
}
