//Created By Ahmed Hamdy Kotp

#ifndef PAYMENT_METHOD_H
#define PAYMENT_METHOD_H

#include <string>
using namespace std;
class PaymentMethod {
protected:
    double amount; 
    string transactionID;
public:
    PaymentMethod(double amountt, const string& TID);   
    virtual bool processPayment() = 0;
    virtual ~PaymentMethod();
};

#endif
