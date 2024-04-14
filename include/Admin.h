//
// Created by OSAMA ASHRAF on 4/1/2024.
//

#ifndef RA7AL_ADMIN_H
#define RA7AL_ADMIN_H
#include "../include/DataFrame/CSVManager.h"

#include "Person.h"

class Admin : public Person {
private:

public:
    // Constructors


    // Destructors


    // Setters


    // Getters


    // Methods
    void showUsers();
    void showUser(int id);
    void addUser();
    void deleteUser(int id);

    void showAirlines();
    void showAirline(int id);
    void addAirline();
    void deleteAirline(int id);

    void showFlights();
    void showFlight(int id);
    void addFlight();
    void deleteFlight(int id);

    void showHotels();
    void showHotel(int id);
    void addHotel();
    void deleteHotel(int id);

    void showPaymentMethods();
    void showPaymentMethod(int id);
    void addPaymentMethod();
    void deletePaymentMethod(int id);


    //Modifying Finance Databases

    void addCurrency(string& filename = "data/currencies.csv");
    void showCurrencies(string& filename="data/currencies.csv");
    void deleteCurrency(string& filename = "data/currencies.csv");
    void changeSpecificinfo(string& filename = "data/currencies.csv");

    void addCountry(string& filename = "data/countries.csv");
    void showAllcountriesData(string& filename = "data/countries.csv");
    void deleteCountry(string& filename = "data/countries.csv");
    void modifySpecificData(string& filename = "data/countries.csv");

    void addPaymentmethod();
    void deletePaymentmethod();

    void editSettings();



    // Overloaded Operators
};


#endif //RA7AL_ADMIN_H
