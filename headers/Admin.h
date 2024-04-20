//
// Created by OSAMA ASHRAF on 4/1/2024.
//

#ifndef RA7AL_ADMIN_H
#define RA7AL_ADMIN_H

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


    void editSettings();



    // Overloaded Operators
};


#endif //RA7AL_ADMIN_H
