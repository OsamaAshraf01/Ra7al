#include "../include/PaymentMethod.h"

// Constructor 
PaymentMethod::PaymentMethod(double amt, const std::string& txnID) : amount(amt), transactionID(txnID) {}
// Destructor
PaymentMethod::~PaymentMethod() {}
