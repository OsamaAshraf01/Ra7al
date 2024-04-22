#ifndef RA7AL_USER_H
#define RA7AL_USER_H
#include "Person.h"
#include <vector>
#include <string>
#include "Itinerary.h"
#include "PaymentMethod.h"
#include "Budget.h"
#include "Language.h"
#include "Person.h"
using namespace std;

class User : public Person // User inherits from Person
{
private:
    vector<Itinerary> itineraries;
    vector<PaymentMethod> payments;
    Budget budget;
    vector<Language> languages;
    vector<string> preferences;

public:
    User();
    User(string nameInput, string emailInput);

    // Setters
    void addItinerary(Itinerary newItinerary);
    void addPayment(PaymentMethod newPayment);
    void setBudget(Budget newBudget);
    void addLanguage(Language newLanguage);

    // Getters
    vector<Itinerary> getItineraries();
    vector<PaymentMethod> getPayment();
    Budget getBudget();
    vector<Language> getLanguages();

    // Methods
    void showPreferences();
    void printDetails();
};

#endif
