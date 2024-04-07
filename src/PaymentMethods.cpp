
// Created By Ahmed Hamdy Kotp

#include "../include/PaymentMethods.h"
#include "Date.h"

using namespace std;



PaymentMethods::PaymentMethods()
{
}

PaymentMethods::PaymentMethods(const vector<Card>& cards, const vector<DigitalWallet>& dw, const vector<BankTransfer>& BT)
{
}

void PaymentMethods::addCard(const string& cardNumber, int cvvNumber, const Date & date, double money) {
    int len = cardNumber.length();
    if (len != 13 && len != 15 && len != 16) {
        throw std::invalid_argument("Invalid card number length.");
    }

    int firstDigit = cardNumber[0] - '0';
    int firstTwoDigits = (cardNumber[0] - '0') * 10 + (cardNumber[1] - '0');

    if (firstDigit == 4) {
        //  VISA 
    }
    else if (firstTwoDigits >= 51 && firstTwoDigits <= 55) {
        //  MasterCard
    }
    else if (firstTwoDigits == 34 || firstTwoDigits == 37) {
        //  AMEX
    }
    else if (firstDigit == 6) {
        //  Discover
    }
    else {
        cout <<"Invalid card number (unrecognized type).";
    }

    //  Luhn algorithm 
    int sum = 0;
    bool alternate = false;

    for (int i = len - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }
        sum += digit;
        alternate = !alternate;
    }

    if (sum % 10 != 0) {
        cout <<" failed !! .\n");
    }
  

    if (cvvNumber < 100 || cvvNumber > 9999) {
        cout << "Invalid CVV number.";
    }

    if !(date.getYear() >= 2024) {
        cout << "Invalid Expiration date !.";
    }
    if !(money >= 0){
        cout << "INvalid number ;";
    }
    cards.push_back({ cardNumber, cvvNumber, date , money });
}

void PaymentMethods::addDigitalWallet(int walletId, const string& walletAddress, const string& currency, double money)
{
    if (walletId < 0) { cout << "Invalid ID \n"; }
    if (walletAddress.empty()){cout<<"Invalid ! \n" }
    if (!isValidCurrency(currency)) {
        cout << ("Unsupported currency.\n");
    }
    if !(money >= 0) {
        cout << "INvalid number ;";
    wallets.push_back({ walletId, walletAddress, currency,money });

}

void PaymentMethods::addBankTransfer(int transferId, const string& accountNum, const string& bank, double money) {
    
    if (transferId <= 0) {
        cout<<"Invalid transfer ID.";
    }
    if (accountNum.empty()) {
        cout<<"Invalid account number.";
    }
    if !(money >= 0) {
        cout << "INvalid number ;";
    transfers.push_back({ transferId, accountNum, bank , money });
}

