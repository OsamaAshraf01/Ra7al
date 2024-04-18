#ifndef RA7AL_USER_H
#define RA7AL_USER_H

#include <vector>
#include <string>
#include "Itinerary.h"
#include "PaymentMethod.h"
#include "Budget.h"
#include "Language.h"
using namespace std;

class User
{
private:
    string email;
    string password;
    vector<Itinerary> itineraries;
    vector<PaymentMethod> payments;
    Budget budget;
    vector<string> preferences;
    Language language;

public:
    User();
    User(string email, string password, vector<Itinerary> itineraries, vector<PaymentMethod> payments, Budget budget, vector<string> preferences, Language language);
    void login(string email, string password);
    void logout();
    bool isLogged();
    bool validEmail(string email);
    void showPreferences();
};

#endif
