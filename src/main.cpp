#include <iostream>
#include "../public/functions.h"
#include "../headers/DataFrame/DataFrame.h"
#include "../headers/Date.h"
#include "../headers/Duration.h"
using namespace std;

// TODO: Config Directory and file
// TODO: Testing Directory

int main()
{
    DataFrame d("../data/flights.csv");
    DataFrame x = d.SELECT({"Departure Date", "Price"}, {"18-04-2024", 350}, LESS_OR_EQUAL)
                      .SELECT({"Origin Airport"}, {"Cairo International Airport"});

    cout << x;

    return 0;
}
