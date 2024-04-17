#include <iostream>
#include "../public/functions.h"
#include "../include/DataFrame/DataFrame.h"
#include "../include/Date.h"
#include "../include/Duration.h"
using namespace std;

// TODO: Config Directory and file
// TODO: Testing Directory

int main() {
    DataFrame d("../data/flights.csv");
    DataFrame x = d.SELECT({"Departure Date", "Price"}, {"18-04-2024", 350}, LESS_OR_EQUAL)
                   .SELECT({"Origin Airport"}, {"Cairo International Airport"});

    cout << x;

    return 0;
}
