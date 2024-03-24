// Created by Ahmed Hamdy Kotp 3/23/2024


#include "Currency.h"
#include "Budget.h"
#include <string>


Currency::Currency() : Value_in_dollars(0.0) 
{
}

double Currency::convert(double& value_in_dollar) 
{
    double dollars;
    cout << "HOw much dollars do you neet ? : "; cin >> dollars;
    cout << "Total of conversion is : " << dollars * 47 << " EGP " << endl;
    cout << "Type 'OK' to ensure the order Or CANCEL to declare it : "; string x; cin >> x;
    if (x == "OK") {
        total_budget += dollars; 
    }
    return total_budget;
}
