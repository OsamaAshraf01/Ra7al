
// Created by Ahmed Hamdy Kotp

#ifndef PAYMENTMETHODS_H
#define PAYMENTMETHODS_H

#include <string>
#include <vector>
#include "Date.h" 

class PaymentMethods {

private:
    vector<Card> cards;
    vector<DigitalWallet> wallets;
    vector<BankTransfer> transfers;
public:
    //constructors
    PaymentMethods();
    PaymentMethods(const vector<Card>& cards, const vector<DigitalWallet>& dw, const vector<BankTransfer>& BT);



    //Attributes
    struct Card {
        string card_num;
        int cvv_num;
        Date expiry_date; 
        double Money;
    };

    struct DigitalWallet {
        int id;
        string address;
        string currencyType;
        double Money;

    };

    struct BankTransfer {
        int id;
        string accountNumber;
        string bankName;
        double Money;

    };

    //Methods
    void addCard(const string& cardNumber, int cvvNumber, const Date& date, double money);
    void addDigitalWallet(int walletId, const string& walletAddress, const string& currency, double money);
    void addBankTransfer(int transferId, const string& accountNum, const string& bank, double money);

};


#endif 
