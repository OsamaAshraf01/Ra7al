#ifndef PAYMENT_METHOD_H
#define PAYMENT_METHOD_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Budget.h"
#include <map>


//Created by Ahmed Hamdy Kotp

using namespace std;
class PaymentMethods {
private :
	string name;
	int account_number;
	Date expiration_date;
	int security_code;
	PaymentType type;
public :
	//constructors
	PaymentMethods();
	PaymentMethods(const string& name,
					const int& accountnum,
					const Date& expiry, 
					const int& sec_code);

	//Destructors
	~PaymentMethods();


	//Setters
	void setname(const string& name);

	//Getters 
	const string& getName() const ;
	int getAccountnum() const;
	Date getExpiration() const;
	int getsecuritycode()const;

	//Methods
	bool process_payment(double amount, Budget& num);
	map<std::string, std::string> get_details() const;
	void set_default();
	bool verify_security_code(int code) const;
};


