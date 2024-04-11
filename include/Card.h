// Created by Ahmed Hamdy Kotp 

#ifndef CARD_H
#define CARD_H
#include "../include/Date.h"
#include "../include/PaymentMethod.h"
#include <string>
using namespace std ;
class Card : public PaymentMethod {
private:
    int cardNumber;
    Date expiryDate;
    int cvv; 
public:

    Card(double amt, const string& txnID, 
    const int& cardNum, 
    const Date& expDate, int cv);
    bool processPayment() override;
    ~Card();
};

#endif 
